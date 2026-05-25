class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int>v(26,0);
        int n=s.length();
        int ans=0;

        int l=0,h=0,mx=-1;
        v[s[0]-'A']=1;

        while(h<=n-1)
        {      
               

               for(int i=0;i<26;i++)
               {
                 mx=max(mx,v[i]);
               }

            if((h-l+1)-mx<=k) 
            { 
               
                ans=max(ans,h-l+1);

                h++;
                if(h>n-1) break;
                v[s[h]-'A']+=1;
                
                
            }

            else{

                v[s[l]-'A']-=1;

                l++;
               
            }


               
              
        }

       
        return ans;
         
        
    }
};