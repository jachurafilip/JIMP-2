//
// Created by filip on 04.05.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <regex>
#include <string>
#include <stdexcept>
#include <iostream>
#include <zconf.h>
#include <ctime>
namespace moviesubs {

    class MovieSubtitles

    {
    public:
        virtual void ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream* input, std::stringstream* output)=0;
    };

    class MicroDvdSubtitles: public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream* input, std::stringstream* output) override;

    };

    class SubRipSubtitles: public  MovieSubtitles
    {
    public:
        void ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream* input, std::stringstream* output) override;
    };

    class SubtitlesException : public std::invalid_argument{
    public:
        SubtitlesException(int line, const std::string &message) : invalid_argument(message) {};
    };

    class NegativeFrameAfterShift : public SubtitlesException{
    public:
        NegativeFrameAfterShift(int line, const std::string &message) : SubtitlesException(line,"Invalid framerate"){};
    };

    class SubtitleEndBeforeStart : public SubtitlesException{
    public:
        SubtitleEndBeforeStart(int line_num, std::string line) : SubtitlesException(line_num,"At line "+std::to_string(line_num)+": "+line), line_{line_num} {};
        int LineAt() const ;

    private:
        int line_;
    };

    class InvalidSubtitleLineFormat : public SubtitlesException{
    public:
        InvalidSubtitleLineFormat(int line_num, const std::string &message) : SubtitlesException(line_num,message), line_{line_num} {};
        int LineAt() const ;

    private:
        int line_;
    };

    class MissingTimeSpecification : public SubtitlesException{
    public:
        MissingTimeSpecification(int line, const std::string &message) : SubtitlesException(line, "Missing Time Specification") {};
    };

    class OutOfOrderFrames : public SubtitlesException{
    public:
        OutOfOrderFrames(int line, const std::string &message) : SubtitlesException(line, "Out Of Order Frames") {};
    };

}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
