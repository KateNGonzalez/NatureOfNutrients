//
//  main.cpp
//  Project3
//
//  Created by Emily Jones on 11/25/20.
//  Copyright © 2020 Emily Jones. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <unordered_map>
#include <stdlib.h>

using namespace std;

void readCSV(unordered_map<string, int> &nutrients,
             unordered_map<string, vector<pair<string, double>>> &helper)
{
    // make map keys
    ifstream myFile("Data.csv");
    if(myFile.is_open())
    {
        string line, nutrientName, food, trash, value;
       
        // Extract the entire first line
        getline(myFile, line);
        stringstream ss(line);
        
        // ignore first two elements so we can only get the nutrients
        getline(ss, trash, ',');
        getline(ss, trash, ',');
        
        // Extract each nutrient name
        while(getline(ss, nutrientName, ','))
        {
            nutrients[nutrientName] = 0;
            helper[nutrientName];
        }
        
        
        // extract actual food and data
        while(getline(myFile, line))
        {
            stringstream ss(line);
            
            // ignore first column, get food from second column
            getline(ss, trash, ',');
            getline(getline(ss, trash, '"'), food, '"');
            
            // get actual pairs of food with data
            for (auto iter = nutrients.begin(); iter != nutrients.end(); iter++)
            {
                getline(ss, value, ',');
                helper[iter->first].push_back(make_pair(food, atof(value.c_str())));
            }
        }
    }
    
    myFile.close();
}

int main(int argc, const char * argv[]) {
    unordered_map<string, int> nutrients; // int will be node later main map data structure, will hold heads to avl trees
    unordered_map<string, vector<pair<string, double>>> helper; // temporarily stores data in vectors to be put in avl tree
    readCSV(nutrients, helper);
    
    for (auto iter = helper.begin(); iter != helper.end(); iter++)
    {
        for (int i = 0; i < iter->second.size(); i++)
        {
            cout << iter->first << i << iter->second[i].first << " " << iter->second[i].second << endl;
        }
    }
    
    return 0;
}

// one main map that we use to access at end
// one temp map that helps us make the avl tree
