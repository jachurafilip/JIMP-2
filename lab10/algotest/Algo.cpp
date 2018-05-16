//
// Created by jachfili on 16.05.18.
//

#include "Algo.h"
namespace algo {
    std::set<std::string> Keys (const std::map<std::string, int> &m) {
        std::set<std::string> output;
        std::transform(m.begin(),m.end(),std::inserter(output,output.begin()),[](std::pair<std::string,int> pair){ return pair.first;});
        return output;
    }

    std::vector<int> Values (const std::map<std::string, int> &m) {
        std::vector<int> output;
        std::transform(m.begin(),m.end(),std::back_inserter(output),[](std::pair<std::string, int> pair){ return pair.second;});
        return output;
    }

    std::vector<int> DivisableBy (const std::vector<int> &m, int divisor)
    {
        std::vector<int> output;
        std::copy_if(m.begin(),m.end(),std::back_inserter(output),[divisor](int number){return number%divisor==0;});
        return output;
    }

    void SortInPlace (std::vector<int> *v)
    {
        std::sort(v->begin(),v->end());

    }

    std::vector<int> Sort (const std::vector<int> &v) {
        std::vector copy = v;
        std::sort(copy.begin(),copy.end());

    }

    void SortByFirstInPlace (std::vector<std::pair<int, int>> *v)
    {
        std::sort(v->begin(),v->end(),[](std::pair<int,int> x, std::pair<int,int>y){return x.first<y.first;});

    }

    void SortBySecondInPlace (std::vector<std::pair<int, int>> *v) {
        std::sort(v->begin(),v->end(),[](std::pair<int,int> x, std::pair<int,int>y){return x.second<y.second;});

    }

    void SortByThirdInPlace (std::vector<std::tuple<int, int, int>> *v)
    {
        std::sort(v->begin(),v->end(),[](std::tuple<int,int,int> x, std::tuple<int,int,int>y){return std::get<2>(x)<std::get<2>(y);});
    }

    std::vector<std::string> MapToString (const std::vector<double> &v) {
        std::vector<std::string> result;
        std::transform(v.begin(),v.end(),std::inserter(result,result.begin()),[](double p){ return std::to_string(p);});
        return result;
    }

    std::string Join (const std::string &joiner, const std::vector<double> &v) {
        return std::__cxx11::string();
    }

    int Sum (const std::vector<int> &v) {
        std::accumulate(v.begin(),v.end(),0);
    }

    int Product (const std::vector<int> &v) {
        std::accumulate(v.begin(),v.end(),1,std::multiplies<int>());
    }

    bool Contains (const std::vector<int> &v, int element) {
        return v.end()!=std::find(v.begin(),v.end(),element);
    }

    bool ContainsKey (const std::map<std::string, int> &v, const std::string &key) {
        return v.count(key);
    }

    bool ContainsValue (const std::map<std::string, int> &v, int value)
    {
        return v.end()!=std::find_if(v.begin(),v.end(),[value](std::pair<std::string,int> pair){return pair.second == value;});
    }

    std::vector<std::string> RemoveDuplicates (const std::vector<std::string> &v) {
        return std::vector<std::string>();
    }

    void RemoveDuplicatesInPlace (std::vector<std::string> *v)
    {

    }

    void InitializeWith (int initial_value, std::vector<int> *v)
    {
        std::fill(v->begin(),v->end(),initial_value);
    }

    std::vector<int> InitializedVectorOfLength (int length, int initial_value)
    {
        std::vector<int> output(length,initial_value);
        return output;

    }

    void CopyInto (const std::vector<int> &v, int n_elements, std::vector<int> *out)
    {
        std::copy_n(v.begin(),n_elements,std::back_inserter(*out));
    }

    int HowManyShortStrings (const std::vector<std::string> &v, int inclusive_short_length)
    {
        return std::count_if(v.begin(),v.end(),[inclusive_short_length](std::string str){return str.length()<=inclusive_short_length;});
    }
}
