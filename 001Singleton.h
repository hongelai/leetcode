class S
{
    public:
        static S& getInstance()
        {
            //why not use it as pointer? because then you can not free it for the reason that you dont know who is referencing it
            static S    instance; // Guaranteed to be destroyed.
                                  // Instantiated on first use.
            return instance;
        }
    private:
        S() {};                   // Constructor? (the {} brackets) are needed here.

        // C++ 03
        // ========
        // override the default copy constructor and assignment operator 
        //so that you can not make a copy of the singleton 
        //(otherwise it would not be a singleton
        S(S const&);              // Don't Implement
        void operator=(S const&); // Don't implement

        // C++ 11
        // =======
        // We can use the better technique of deleting the methods
        // we don't want.
        S(S const&)               = delete;
        void operator=(S const&)  = delete;

};

/*
Why does everybody want to return a singleton as a pointer?
Return it as a reference seems much more logical!

You should never be able to free a singleton manually. How do you know who is keeping a reference to the singleton? If you don't know (or can't guarantee) nobody has a reference (in your case via a pointer) then you have no business freeing the object.

Use the static in a function method.
This guarantees that it is created and destroyed only once. It also gives you lazy initialization for free.
*/
int main ()
{
  S &s = S::getInstance();
  s.pow = 10;
  S &aa = S::getInstance();
  aa.pow = 11;
  cout<<s.pow<<endl; // 11

    return 0;
}
