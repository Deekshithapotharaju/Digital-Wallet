#include<bits/stdc++.h>
using namespace std;
struct User {
int userID;
int balance;
};
int index(vector<User>& users, int userID) {
for (int i = 0; i < users.size(); i++) {
     if (users[i]. userID == userID) {
         return i;
     }
  }
  return -1;
}
void tran(vector<User>& users, int from_userID, int to_userID,int amount){
     int fromIndex = index(users, from_userID);
     int toIndex = index( users, to_userID );
     if (fromIndex!= -1 && toIndex!= -1 && users[fromIndex]. balance >= amount) {
         users[fromIndex]. balance -= amount;
         users[toIndex]. balance += amount;
         cout << "Success" << endl;
     } else {
         cout << "Failure" << endl;
     }
}
bool cmp( const User& a, const User& b) {
    if (a.balance == b.balance) {
        return a.userID < b.userID;
    }
return a.balance < b.balance;
}
int main() {
    int n,t;
    cin >> n;
    vector<User> users(n);
    for (int i = 0; i < n; i++) {
        cin >> users[i]. userID >> users[i]. balance;
    }
    cin >> t;
    while(t--) {
       int from_userID,to_userID,amount;
       cin>>from_userID >> to_userID >> amount;
       tran(users, from_userID, to_userID, amount);
    }
   sort(users. begin(), users. end(), cmp);
   cout<<endl;
   for ( const auto & user : users ) {
       cout << user. userID << " " << user. balance << endl;
   }
   return 0;
}