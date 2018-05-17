//
// Created by filip on 17.05.18.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <cstdlib>
#include <set>

namespace academia {

    class SchedulingItem {
    public:
        SchedulingItem(int course, int teacher, int room, int time, int year);
        int CourseId()const ;
        int TeacherId()const ;
        int RoomId()const ;
        int TimeSlot()const ;
        int Year()const ;

    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot;
        int year_;


    };

    class Schedule
    {
    public:
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id)const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots)const;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;
        const SchedulingItem &operator[](int id)const;

        std::vector<SchedulingItem> items_;


    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
