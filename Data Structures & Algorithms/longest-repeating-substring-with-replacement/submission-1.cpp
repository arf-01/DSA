class Solution {
public:
    int characterReplacement(string s, int k) {

       // vector<int>v(26,0);
       vector<int>mp(26,0);
        int n=s.length();
        int ans=1;

        int l=0,h=0,mx=1;
        mp[s[0]-'A']=1;

        while(h<=n-1 )
        {      
               

               

            if((h-l+1)-mx<=k) 
            { 
               
                ans=max(ans,h-l+1);

                h++;
                if(h>n-1) break;
                mp[s[h]-'A']+=1;
                mx=max(mx,mp[s[h]-'A']);
                
                
                
                
            }

            else{

                mp[s[l]-'A']-=1;

                l++;
               
            }


               
              
        }

       
        return ans;
         
        
    }
};