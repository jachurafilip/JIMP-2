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

    class Scheduler
    {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                            const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                            const std::map<int, std::set<int>> &courses_of_year,
                                            int n_time_slots)=0;
    };

    class NoViableSolutionFound: public std::exception {};

    class GreedyScheduler: public Scheduler
    {
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                            const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                            const std::map<int, std::set<int>> &courses_of_year,
                                            int n_time_slots) override;

        int MatchYearToCourse(const std::map<int,std::set<int>> &courses_on_year, int course)const;
        std::pair<int, int> TimeAndPlace(const Schedule &schedule, int teacher, const std::vector<int> &rooms, int n_time_slots, int year)const;

    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
