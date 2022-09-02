#include "CCazare.h"
#include<algorithm>
pair<CData, CData> CCazare::get_maxim_checkout()
{
    auto lambda = [](pair<CData, CData >& a, pair<CData, CData >& b) {return a.second.make_comparable_date() > b.second.make_comparable_date(); };
    return *max_element(date_rezervate.begin(), date_rezervate.end(), lambda);
}

pair<CData, CData> CCazare::get_minim_checkin()
{
    auto lambda = [](pair<CData, CData >& a, pair<CData, CData >& b) {return a.first.make_comparable_date() < b.first.make_comparable_date(); };
    return *min_element(date_rezervate.begin(), date_rezervate.end(), lambda);
}
