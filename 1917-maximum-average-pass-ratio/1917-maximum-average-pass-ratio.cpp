class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
//      classes={(1,2),(3,5),(2,2)}
//      extra=2
//      pass_ratio= {0.5,0.6,1}
//      if we want to increase avg pass ratio then we must try to increate pass ratio of class with small
// with smallest pass_ratio first
// we should add 1 student to class with pass ratio 0.5
// then again check the smallest pass ratio and assign another student to that class
// after assigning 1 student to class 0
// classes={(2,3),(3,5),(2,2)}
// pass_ratio={0.66666,0.6,1.00000}
// now pass_ratio of class 1 is smallest, assign remaining 1 student to class 1
// classes={(2,3),(4,6),(2,2)}
// pass_ratio={0.66666,0.6666,1.00000}
// avg_ratio after assigning all the extrastudents= sum of all the pass_ratio/number of class
//  we get avg_ratio= 0.77777 but expected answer is 0.78333
// hence assigning students to lower pass_ratio is not a correct approach 

// classes={(6,10),(4,6)}, extra=1
// pass_ratio= {0.60000,0.66667}
// assign 1 to class 0
// classes={(7,11),(4,6)}
// pass_ratio= {0.54545,0.66667}
// avg_passratio=0.60606
// assign 1 to class 1
// classes={(6,10),(5,7)}
// pass_ratio= {0.60000,0.71429}
// avg_passratio=0.65714
// hence it's not clear how to assign extrastudents to classes

// correct approach:
// find initial pass ratio of each  classes, assign students to each class, 
// and again find the pass ratio of each classes
// now find the change in pass ratio of each class, the extrastudents will be assigned
// to class with maximum difference 
// classes={(1,2),(3,5),(2,2)}, extra=2
// pass_ratio= {0.50000,0.60000,1.00000}
// assign 1 student to each class
// classes={(2,3),(4,6),(3,3)}
// pass_ratio={0.66667,0.66667,1.00000}
// delta= class0=>0.16667
// class1=>0.06667
// class2=>0.00000
// class0 has the highest change hence we will assign the student to class 0
// classes={(2,3),(3,5),(2,2)}, extra=1
// pass_ratio={0.66667,0.60000,1.00000}
//  for the reaminin 1 student we will do the same
//  classes={(3,4),(4,6),(3,3)}
//  pass_ratio={0.75000,0.66667,1.00000}

// delta= class0=>0.08333
// class1=>0.06667
// class2=>0.00000

// assign remaining 1 student to class0
// classes={(3,4 ),(3,5),(2,2)}
// pass_ratio= 0.75000,0.60000,1.00000
// final_pass_ratio= 0.7833
 
// find current pass ratio of each class
// assign student one by one to each class , find the class with maximum delta 
// update the pass ratio
// keep assigning student to each class until extrastudents become 0
// find avg pass ratio 
// o(n^2)
// int n=classes.size();
// vector<double>pass_ratio(n);
// for(int i=0;i<n;i++){
//     double ratio= (double)classes[i][0]/classes[i][1];
//     pass_ratio[i]=ratio;
// }

// while(extraStudents--){ //o(n): in worst case it will be 10^5   
//     vector<double>updated_passratio(n);
//     for(int i=0;i<n;i++){
//         double newRatio=(double)(classes[i][0]+1)/(classes[i][1]+1);
//         updated_passratio[i]=newRatio;
//     }
//     int bestClassIdx=0;
//     double bestDelta=0;
//     for(int i=0;i<n;i++){ //0(n)-> optimize this using heap, to find max or min in o(1) time     
//         // maxheap will store the delta with class index 
//         double delta=updated_passratio[i]-pass_ratio[i];
//         if(delta>bestDelta){
//             bestDelta=delta;
//             bestClassIdx=i;
//         }
//     }
//     pass_ratio[bestClassIdx]=updated_passratio[bestClassIdx];
//     classes[bestClassIdx][0]++;
//     classes[bestClassIdx][1]++;

// }
// double result=0.0;
// for(int i=0;i<n;i++){
//  result+=pass_ratio[i];
// }

// return result/n;

int n=classes.size();
priority_queue<pair<double,int>>pq;
for(int i=0;i<n;i++){
    double current_pr= (double)(classes[i][0])/(classes[i][1]);
    double new_pr=(double)(classes[i][0]+1)/(classes[i][1]+1);
    double delta= new_pr-current_pr;
    pq.push({delta,i});
}
while(extraStudents--){
    auto curr=pq.top();
    pq.pop();

    double delta= curr.first;
    int idx=curr.second;

    classes[idx][0]++;
    classes[idx][1]++;

    double current_pr=(double)(classes[idx][0])/(classes[idx][1]);
     double new_pr=(double)(classes[idx][0]+1)/(classes[idx][1]+1);
      delta= new_pr-current_pr;
    pq.push({delta,idx});
}
double result=0.0;
for(int i=0;i<n;i++){
    result+=(double)classes[i][0]/classes[i][1];
}
return result/n;
    }
};