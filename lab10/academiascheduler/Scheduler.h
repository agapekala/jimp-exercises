//
// Created by DELL on 15.05.2017.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H


#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

namespace academia{

    class SchedulingItem{
    public:
        SchedulingItem();
        SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year):course_id_(course_id), teacher_id_(teacher_id), room_id_(room_id), time_slot_(time_slot), year_(year){}
        ~SchedulingItem();
        int TeacherId() const;
        int CourseId() const ;
        int RoomId() const;
        int TimeSlot() const;
        int Year()const;

    private:
        int course_id_, teacher_id_, room_id_, time_slot_, year_;
    };

    class Schedule{
    public:
        Schedule();
        Schedule(std::initializer_list<SchedulingItem> &schedule): schedule_(schedule){};
        ~Schedule();
        void InsertScheduleItem(const SchedulingItem &item);
        SchedulingItem operator[](int el) const;
        int Size() const;
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;

    private:
        std::vector<SchedulingItem> schedule_;
    };

    class NoViableSolutionFound{
    public:
        NoViableSolutionFound();
        ~NoViableSolutionFound();
    };

    class Scheduler{
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots)=0;
    };

    class GreedyScheduler: public Scheduler{
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override ;
    };
}


#endif //JIMP_EXERCISES_SCHEDULER_H