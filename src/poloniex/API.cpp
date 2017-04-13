#include "API.hpp"

using namespace sf;
using namespace std;

namespace plnx{
    API::API(string Secret, string API_Key):_poloniexConnexion("https://poloniex.com/")
    {

    }

    string API::requestWebApi(map<string, string>getParameters, string>(), map<string, string>postParameters, string>())
    {
        sf::Http::Request request;
        request.setMethod(sf::Http::Request::Post);
        request.setField("Sign")
    }

}
