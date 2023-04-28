#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> pq;


bool isPrime(int n) {

    bool is_prime = true; 
    int i = 2; 

    if (n == 0 || n == 1) {
        is_prime = false;
        return is_prime;
  }

  // loop to check if n is prime
  for (i = 2; i <= n/2; ++i) {
    if (n % i == 0) {
      is_prime = false;
      return is_prime;
      //break;
    }
  }
  return is_prime;
  
};

void findFactors (int num) {

   int product;
  // cout << "goes in function" << endl;

   for (unsigned i = 2; i < num; ++i){
    //cout << "in loop";
      if (isPrime(i)){
         for(unsigned j = 2; j < num; ++j){
            if(isPrime(j)){
               //cout << "loop"; 
                product = i*j;
               
               if (product == num){
                 // cout << "loop inside";
                  pq.push_back(i);
                  pq.push_back(j);
                  break;
               }

            }
         }
      }
   }
   
//    for loop (int i - 900)
//         check if i prime  -> isPrime
//         if isPrime: 
//             for loop (j - 900)
//                 check if is Prime -> isPrime
//                 if isPrime: multiply it with i 
//                     check if equal to num; 

// check all prime numbers from 1 = square root(n)
};



int findPhi()
{
   int p = pq.at(0);
   int q = pq.at(1);
    int phiN;
    phiN = (p-1)*(q-1);
    return phiN;

};
int findD(int e, int phi){
    int d; 
    int tempD1;
    int tempD2; 
    
    vector<int> multiplesofe;
    for (int i = 1; i < phi; ++i) {
        //cout << "in the multiples loop" << endl;
        int num = i * e;
        //cout << num << " ";
        multiplesofe.push_back(num);
    }
    cout << endl;

    // for (int i = 0; i < multiplesofe.size(); ++i)
    // {
    //   cout << "multiples of e: " << multiplesofe.at(i) << " " << endl;
    // }
    //cout << "out of loop" << endl;

   //  for (int i = 0; i < pq.size(); ++i)
   //  {
   //    if (pq.at(i) < phi)
   //    {
   //       pq.pop_front();
   //    }
   //  }

    for (int i = 2; i < phi; ++i){
       // cout << "in the phi loop" << endl;
        for (int j = 1; j < multiplesofe.size(); ++j) {
            //cout << "in the check phi and multofe loop " << j << endl;
            if ((phi * i) == (multiplesofe.at(j)+1) || (phi * i) == (multiplesofe.at(j)-1)){
                tempD1 = i;
                //cout << tempD1 << endl;
                tempD2 = j+1;
                //cout << tempD2 << endl;
                i = phi;
                break;
                
            }
        }
    
    }
    if((tempD2*e - tempD1*phi) == 1) {
        
        d = tempD2;

    }else {
        d = tempD1; 
    }

    return d;
}

//C^d(mod n) = 1
int modBySquares (int C, int d, int n){
    int constant = 1;
    int end;
    while (d > 1){
        if (d % 2 != 0){
            constant = constant * C; 
            constant = constant % n;
            --d;
        }
        C = C * C; 
        C = C % n;
        d = d / 2;
    }

    end = (C * constant) % n;
    return end;
}

int main()
{ 
    int encryptedMsg[130] = { 030, 673, 332, 785, 171, 589, 782, 171, 828, 589, 785, 568,
                                782, 785, 713, 782, 813, 785, 123, 589, 828, 673, 589, 487,
                                589, 785, 813, 890, 243, 813, 785, 733, 243, 813, 890, 589,
                                733, 243, 813, 673, 422, 769, 785, 673, 769, 785, 769, 673,
                                733, 171, 828, 589, 291, 785, 673, 813, 785, 673, 769, 785,
                                782, 713, 828, 482, 785, 123, 589, 422, 243, 500, 769, 589,
                                785, 813, 890, 589, 482, 785, 568, 782, 785, 713, 782, 813,
                                785, 549, 589, 243, 828, 673, 367, 589, 785, 890, 782, 587,
                                785, 422, 782, 733, 171, 828, 673, 422, 243, 813, 589, 568,
                                785, 828, 673, 332, 589, 785, 673, 769, 777, 030};
                    
    string message[31] = {
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
        " ", "\"", ". ", ", ", " '"
    };

    int phi;
    int d;
    int n;
    cout << "Enter a n value" << endl; 
    cin >> n;
    int e;
    cout << "Enter an e value" << endl;
    cin >> e;
    int decrypt;
    
//    if(isPrime(367)) {
//      cout << "yes its prime" << endl;
//    }else{
//     cout << "no" << endl;
//    }

   
   
    findFactors(n);
    cout << pq.at(0) << " " << pq.at(1) << " ";
    phi = findPhi(); 
    cout << phi << " ";
    d = findD(e,phi);
    cout << d << " " << endl;
    
    for (int i = 0; i < 32; ++i){
        decrypt = modBySquares(encryptedMsg[i],d,n);
        cout << message[decrypt-3]; 
    }
    
     
    // cout << d << endl;
    

//GET PUBLIC KEY P(e,n)
//FIND p,q,phi(n),d

//1.Find the factors of n

//2.used the totiet rule to find phi(n)
//3.find d: for loop 
//4.get letter 

   return 0;
};