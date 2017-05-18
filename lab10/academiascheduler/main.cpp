//
// Created by DELL on 15.05.2017.
//
#include "Scheduler.h"
#include <memory>
using::academia::SchedulingItem;
using::academia::Schedule;
using::academia::Scheduler;
using::academia::GreedyScheduler;
using::academia::NoViableSolutionFound;

int main(){
    std::unique_ptr<Scheduler> scheduler = std::make_unique<GreedyScheduler>();

    std::vector<int> rooms{1000};
    std::map<int, std::vector<int>> teachers{std::make_pair(100, std::vector<int>{10, 20}), std::make_pair(200, std::vector<int>{30}),
                                   std::make_pair(300, std::vector<int> {40})};
    std::map<int, std::set<int>> years{std::make_pair(1, std::set<int>{10, 20}), std::make_pair(2, std::set<int>{30, 40})};

    Schedule schedule;
    
    scheduler->PrepareNewSchedule(rooms, teachers, years, 10);
}