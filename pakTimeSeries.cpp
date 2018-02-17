#include <TimeSeries.h>
// #include <TSValue.h>
#include <stdint.h>
#include <cstring>
#include <iostream>
#include <vector>
#include "math.h"
#include <stdio.h>

extern "C" void save_series_(char *ime,double* vreme,double* serie,int64_t &serie_steps,int64_t &serie_pts,int &current,int &n, int &ind);

void save_series_(char *ime,double* vreme,double* serie,int64_t &serie_steps,int64_t &serie_pts,int &current,int &n, int &ind)
{
    int64_t i,start;
    TimeSeries ts;
    typedef double (*serie2D)[serie_steps];
    serie2D s2D = (serie2D) serie;
    
    if(ind == 1)
    {
        start=0;
    }else{
        start=1;
    }
    for (i=start ; i<serie_steps ; i++) 
    {
        ts.addValue(vreme[i]*86400,s2D[current][i],0.0);
    }
    char imeC[n];
    for (i=15-n;i<15;i++)
    {
        imeC[i-15+n]=ime[i];
    }
     
    std::string a(imeC);
    std::string st;
    st = a.substr(0, a.size()-(a.size()-n));
    std::string b;
    b="_pak.tab";
    std::string imeCpak = st+b;
    ts.toFEQ(imeCpak);
}

