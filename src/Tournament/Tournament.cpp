#include "GameEngine/StrassbourgEngine.h"

#include <cmath>
#include <iostream>
#include <algorithm>
#include <random>


namespace Go::GameEngine::Player {

enum class MoveType { move, pass, resign };

struct Move
{
    MoveType type;
    Point point;
};

template <typename PLAYER, typename Engine>
struct Player{

    Move nextMove(GameEngine<Engine> & engine, Stone stone)
    {
        return static_cast<PLAYER *>(this)->nextMove(engine, stone);
    }

};

template <typename Engine>
struct Contestant
{
    Contestant(int rank, std::string contestant_name): ranking{rank}, name{contestant_name}{}
    virtual Move nextMove(GameEngine<Engine> & engine, Stone stone) = 0;

    int ranking;
    std::string name;
};

template <typename Engine>
struct ResignPlayer : public Player<ResignPlayer<Engine>, Engine>, Contestant<Engine>
{
    ResignPlayer(): Contestant<Engine>{2000, "Resign"} {}
    Move nextMove(GameEngine<Engine> &, Stone) override {return Move{MoveType::resign, {}};}
};

template <typename Engine>
struct PassPlayer : public Player<ResignPlayer<Engine>, Engine>, Contestant<Engine>
{
    PassPlayer(): Contestant<Engine>{2000, "Pass"} {}
    Move nextMove(GameEngine<Engine> &, Stone) override {return Move{MoveType::pass, {}};}
};

template <typename Engine>
struct RandomPlayer : public Player<ResignPlayer<Engine>, Engine>, Contestant<Engine>
{
    RandomPlayer(): Contestant<Engine>{2000, "Random"} {};

    Move nextMove(GameEngine<Engine> & engine, Stone stone) override {
        std::uniform_int_distribution<int> rowDistribution(0, engine.board().getDimension().row);
        std::uniform_int_distribution<int> columnDistribution(0, engine.board().getDimension().row);


        int row = rowDistribution(generator);
        int column = columnDistribution(generator);

        for(int limit = 1000; not engine.is_play_valid(stone, row, column); --limit)
        {
            row = rowDistribution(generator);
            column = columnDistribution(generator);

            if(limit <= 0)
            {
                return Move{MoveType::pass, {}};
            }
        }

        return Move{MoveType::move, {row, column}};
    }

private:
    std::default_random_engine generator;
};

template <typename Engine>
Score compete(Contestant<Engine> * black, Contestant<Engine> * white)
{
    Engine engine{};

    while(engine.state() != GameState::game_over && engine.state() != GameState::end_of_game)
    {
       if(engine.state() == GameState::start || engine.state() == GameState::turn_black)
       {
           const auto move = black->nextMove(engine, Stone::black);

           if(move.type == MoveType::move)
           {
               engine.play_black(move.point.row, move.point.column);
           }else if(move.type == MoveType::pass)
           {
               engine.play_black_pass();
           }else {
                engine.play_black_resign();
            }
       }else
       {
           const auto move = white->nextMove(engine, Stone::white);

           if(move.type == MoveType::move)
           {
               engine.play_white(move.point.row, move.point.column);
           }else if(move.type == MoveType::pass)
           {
               engine.play_white_pass();
           }else {
                engine.play_white_resign();
            }
       }
    }

    return engine.score();
}


} // Go::GameEngine::Player






int main()
{
    using namespace Go::GameEngine::Player;

    constexpr int numberOfRounds = 100;

    using UsedEngine = Go::GameEngine::StrassbourgEngine;

    ResignPlayer<UsedEngine> resign{};
    PassPlayer<UsedEngine> pass{};
    RandomPlayer<UsedEngine> random{};

    std::vector<Contestant<UsedEngine>*> contestants{&random, &random, &pass, &resign};

    if(contestants.size()% 2 != 0)
    {
        throw std::runtime_error("not enough contestants");
    }

    auto rng = std::default_random_engine {};

    for(int i = 0; i < numberOfRounds; ++i)
    {
        std::shuffle(contestants.begin(), contestants.end(), rng);

    for(auto iterator = contestants.begin(); iterator != contestants.end(); iterator=iterator+2)
    {
        const auto player_black = *iterator;
        const auto player_white = *(iterator+1);
        const auto result = compete(player_black, player_white);

        float estimate_black = 1/(1+std::pow(10, (player_white->ranking - player_black->ranking)/400));
        float estimate_white = 1-estimate_black;

        float result_value_black = [&](){
            if(result.type == Go::GameEngine::ScoreType::jigo)
            {
                return 0.5;
            }
            if(result.type == Go::GameEngine::ScoreType::win_by_resign || result.type == Go::GameEngine::ScoreType::score)
            {
            if(result.winner == Go::Stone::black)
            {
                return 1.0;
            }else
            {
                return 0.0;
            }
            }
            if(result.type == Go::GameEngine::ScoreType::ongoing)
            {
                if (result.black == result.white)
                {
                    return 0.5;
                }else if( result.black>result.white)
                {
                    return 1.0;
                }else
                {
                    return 0.0;
                }
            }
            return 0.0;
        }();

        float result_value_white = 1-result_value_black;

        player_black->ranking = player_black->ranking + 50*(result_value_black-estimate_black);
        player_white->ranking = player_white->ranking + 50*(result_value_white-estimate_white);
    }
    }

    std::sort(contestants.begin(), contestants.end(), [](const auto & left, const auto & right){return left->ranking>right->ranking;});

    std::for_each(contestants.begin(), contestants.end(), [](const auto & contest){
        std::cout << "Name: " << contest->name << ", ranking: " << contest->ranking << '\n';
    });

    return 0;
}
