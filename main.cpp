//
//  main.cpp
//  BankQueue
//
//  Created by Stefán Hafsteinsson on 06/12/14.
//  Copyright (c) 2014 Stefán Hafsteinsson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Costumer
{
    int money;
    int waitTime;
    
    Costumer(int mon, int wait)
    {
        money = mon;
        waitTime = wait;
    }
    
    

};

/*
 * Compares the costumers by their money.
 */
bool compareByAmount(const Costumer &a, const Costumer &b)
{
        return a.money >= b.money;
}

/*
 * Put's the customer in the right spot int the queue. If his spot and all spots below him are occupied,
 * then we cannot serve him.
 */
void queueCostumer(vector<int> &vec, Costumer c)
{
    int i = c.waitTime;
    
    while(i >= 0)
    {
        if(vec[i] == 0)
        {
            vec[i] = c.money;
            return;
        }
        
        i--;
    }
    
}

int main(int argc, const char * argv[]) {
    
    int N, T, amount, minutes;
    
    
    scanf("%d%d", &N, &T);
    
    //The queue of the selected customers.
    vector<int> bQueue(T);
    vector<Costumer> money;
    
    for(int i = 0; i < N; i++)
    {
        scanf("%d%d", &amount, &minutes);
        Costumer c(amount, minutes);
        
        money.push_back(c);
    }
    
    //Sort by costumers amount of money.
    sort(money.begin(), money.end(), compareByAmount);
    
    int sum = 0;
    int i = 0;
    
    //Set selected custumers in the bank queue.
    while(i < money.size())
    {
        queueCostumer(bQueue, money[i]);
        
        i++;
    }
    
    //Service each customer.
    for(int i = 0; i < bQueue.size(); i++)
    {
        sum += bQueue[i];
    }
    
    cout << sum;
    
    return 0;
}
