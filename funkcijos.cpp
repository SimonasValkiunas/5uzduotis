#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>

typedef std::multimap<std::string, int>::iterator MMit;


void Naikinti (std::string &s, char c) {
    auto pos = s.find(c);
    if (pos != std::string::npos)
    s.erase(s.begin() + pos, s.begin() + pos + 1);
}

void Printinimas (std::string failas, std::multimap<std::string, int> &Mmap){
    std::ofstream fr (failas + ".txt");
        fr <<std::left<< std::setw(15) << "Zodis"<<std::setw(15)<< "Pasikartoja"<<std::setw(10)<<"Eilutese"<<std::endl;
        for( MMit it = Mmap.begin(); it != Mmap.end(); it = Mmap.upper_bound(it->first))
        {
            int count = Mmap.count(it->first);
            if(count > 1) {
                std::pair<MMit, MMit> result = Mmap.equal_range(it->first);
                fr <<std::left<< std::setw(15) << it->first << std::setw(15) << count;
                std::set<int> s;
                for (MMit itx = result.first; itx != result.second; itx++){

                    s.insert(itx->second);
                }
                for (auto v: s) fr<<v<<" ";
                fr<<std::endl;
            }

        }
        fr.close();
}

void Nuskaitymas (std::string failas, std::multimap<std::string, int> &Mmap )
{
    std::ifstream fd(failas + ".txt");

        std::string line;
        std::string zodis;
        int eilute = 1;
        while(std::getline(fd,line))
        {
            std::istringstream ss(line);
            while (ss>>zodis){
                Naikinti(zodis, '(');
                Naikinti(zodis, ')');
                Naikinti(zodis, '"');
                Naikinti(zodis, ',');
                Naikinti(zodis, '.');
                Naikinti(zodis, '“');
                Naikinti(zodis, '?');
                Naikinti(zodis, '”');
                Naikinti(zodis, '!');
                Naikinti(zodis, '—');
                Naikinti(zodis, ':');
                Naikinti(zodis, '\u0093');
                std::transform(zodis.begin(), zodis.end(), zodis.begin(), ::tolower);
                int found = zodis.find('');
                if( found != std::string::npos){
                    std::string::iterator itx = zodis.begin()+found;
                    std::string::iterator it = zodis.end();
                    if(zodis[found+1]=='t') {
                                    zodis.erase(itx-2,it);
                                    Mmap.insert(std::pair <std::string, int> ("not",eilute));}
                    if(zodis[found+1]=='s') {
                        Mmap.insert(std::pair <std::string, int> ("is",eilute));
                        zodis.erase(itx,it);
                        Mmap.insert(std::pair <std::string, int> (zodis,eilute));
                    }
                    if(zodis[found+1]=='v') {
                        zodis.erase(itx,it);
                        Mmap.insert(std::pair <std::string, int> (zodis,eilute));
                        Mmap.insert(std::pair <std::string, int> ("have",eilute));
                    }
                    if(zodis[found+1]=='d')
                    {Mmap.insert(std::pair <std::string, int> ("had",eilute));
                    zodis.erase(itx,it);
                    Mmap.insert(std::pair <std::string, int> (zodis,eilute));}
                    } else Mmap.insert(std::pair <std::string, int> (zodis,eilute));

            }
            eilute++;
        }
        Mmap.erase("");
        fd.close();

}
