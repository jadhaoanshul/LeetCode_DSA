class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> cp(n);//{capital,profit};
        priority_queue<int,vector<int>> pq;//store only profit in maxheap
        for(int i=0;i<n;i++){
            cp[i]={capital[i],profits[i]};
        }

        sort(cp.begin(),cp.end());//sort based on capital

        int i=0;
        while(k--){//ensures that only k projects are completed
            while(i<n && cp[i].first<=w){
                pq.push(cp[i].second);
                i++;
            }
            if(!pq.empty())
            {
             w+=pq.top();
             pq.pop();
            }
        }
        return w;
    }
};