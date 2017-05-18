//
// Created by DELL on 15.05.2017.
//

#include <map>
#include "Scheduler.h"


namespace academia{

    SchedulingItem::~SchedulingItem() {}

    int SchedulingItem::TeacherId() const{
        return teacher_id_;
    }

    int SchedulingItem::CourseId() const{
        return course_id_;
    }

    int SchedulingItem::RoomId() const{
        return room_id_;
    }

    int SchedulingItem::TimeSlot() const{
        return time_slot_;
    }

    int SchedulingItem::Year() const{
        return year_;
    }

    SchedulingItem::SchedulingItem() {}

    Schedule::Schedule() {}


    Schedule::~Schedule() {}

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        schedule_.push_back(item);
    }

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule teacher;
        std::copy_if (schedule_.begin(), schedule_.end(), std::back_inserter(teacher.schedule_), [teacher_id](SchedulingItem i){return (i.TeacherId()==teacher_id);});
        return teacher;
    }

    int Schedule::Size() const {
        return schedule_.size();
    }

    SchedulingItem Schedule::operator[](int el) const{
        return schedule_[el];
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule room;
        std::copy_if (schedule_.begin(), schedule_.end(), std::back_inserter(room.schedule_), [room_id](SchedulingItem i){return (i.RoomId()==room_id);});
        return room;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule year_num;
        std::copy_if (schedule_.begin(), schedule_.end(), std::back_inserter(year_num.schedule_), [year](SchedulingItem i){return (i.Year()==year);});
        return year_num;
    }
    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> time1;
        std::vector<int> time2;
        std::vector<int> output;
        for (int i=1; i<=n_time_slots; i++){
            time2.push_back(i);
        }
        std::transform(schedule_.begin(), schedule_.end(), std::back_inserter(time1), [](SchedulingItem n) { return n.TimeSlot(); });
        std::set_difference(time2.begin(), time2.end(), time1.begin(), time1.end(),
                            std::inserter(output, output.begin()));
        return output;
    }

    NoViableSolutionFound::NoViableSolutionFound() {}

    NoViableSolutionFound::~NoViableSolutionFound() {}


    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {

        Schedule schedule;
        int iter_slots=1,iter_room=0, slot=0, year=0, teacher=0, course=0, room=0;
        int prev_course=0, prev_room=0;
        for(auto t:teacher_courses_assignment){
            for(auto c:t.second){
                teacher=t.first;
                course=c;
                for(auto cr:courses_of_year){
                    for(auto crs:cr.second){
                        if(crs==c){year=cr.first;}
                    }
                }
                room=rooms[iter_room];
                slot=iter_slots;
                if(iter_slots%n_time_slots==0){
                    iter_slots=0;
                    iter_room++;
                }
                iter_slots++;
                schedule.InsertScheduleItem(SchedulingItem{course, teacher, room, slot, year});
                if(prev_course==course and prev_room!=room){
                    throw NoViableSolutionFound();
                }
                prev_course=c;
                prev_room=room;
            }
        }

        int all = 0;
        for (auto c: teacher_courses_assignment) {
                for(auto cs: c.second){
                    all++;
                }
        }

        if(rooms.size()*n_time_slots<all){
            throw NoViableSolutionFound();
        }
        return schedule;
    }

}