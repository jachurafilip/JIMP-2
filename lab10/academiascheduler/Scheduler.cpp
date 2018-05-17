//
// Created by filip on 17.05.18.
//

#include <algorithm>
#include "Scheduler.h"

namespace academia
{

    int SchedulingItem::CourseId()const {
        return course_id_;
    }

    int SchedulingItem::TeacherId()const {
        return teacher_id_;
    }

    int SchedulingItem::RoomId()const {
        return room_id_;
    }

    int SchedulingItem::TimeSlot()const {
        return time_slot;
    }

    int SchedulingItem::Year()const {
        return year_;
    }

    SchedulingItem::SchedulingItem(int course, int teacher, int room, int time, int year): course_id_{course}, teacher_id_{teacher}, room_id_{room},time_slot{time},year_{year}{}

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule tmp;
        std::copy_if(items_.begin(),items_.end(),std::back_inserter(tmp.items_),[teacher_id](const SchedulingItem &el){return el.TeacherId()==teacher_id;});
        return tmp;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule tmp;
        std::copy_if(items_.begin(),items_.end(),std::back_inserter(tmp.items_),[room_id](const SchedulingItem &el){return el.RoomId()==room_id;});
        return tmp;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule tmp;
        std::copy_if(items_.begin(),items_.end(),std::back_inserter(tmp.items_),[year](const SchedulingItem &el){return el.Year()==year;});
        return tmp;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const
    {
        std::vector<int> taken, free;
        for (auto &v: items_)
        {
            taken.push_back(v.TimeSlot());
        }
        for(int i=1; i<=n_time_slots;i++)
        {
            if(std::find(taken.begin(),taken.end(),i)==taken.end())
            {
                free.push_back(i);
            }
        }
        return free;
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item)
    {
        items_.emplace_back(item);
    }

    size_t Schedule::Size() const {
        return items_.size();
    }

    const SchedulingItem &Schedule::operator[](int id) const {
        return (items_[id]);
    }
}