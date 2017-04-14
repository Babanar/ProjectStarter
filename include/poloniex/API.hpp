#ifndef API_HPP
#define API_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>


using namespace std;
using namespace sf;

namespace plnx{

    class API
    {
        public:
            API(string Secret="", string API_Key="");

            void setSecret(string Secret) { _Secret = Secret; }
            void setAPI_Key(string API_Key) { _API_Key = API_Key; }

            static string getTicker();

        protected :

            string requestWebApi(map<string,string> getParameters = map<string,string>()
                                 ,map<string,string> postParameters = map<string,string>());

            static string requestPublicWebApi(map<string,string> getParameters = map<string,string>());

        protected:
            string _Secret;
            string _API_Key;
            static Http _poloniexConnexion;

        private:
    };
}

#endif // API_HPP
