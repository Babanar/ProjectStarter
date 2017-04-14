#include "poloniex/API.hpp"

#include <map>
#include <iostream>

using namespace sf;
using namespace std;

namespace plnx{

    Http API::_poloniexConnexion("https://poloniex.com/");

    API::API(string Secret, string API_Key)
    {

    }

    string API::requestWebApi(map<string, string> getParameters, map<string, string> postParameters)
    {

    }

    string API::requestPublicWebApi(map<string, string> getParameters)
    {

        if(getParameters.find("command")==getParameters.end())
            return "";

        string cmd = "public?command="+getParameters["command"];
        for(map<string,string>::iterator it=getParameters.begin();it!=getParameters.end();++it)
        {
            if(it->first=="command") continue;
            cmd+="&"+it->first+"="+it->second;
        }
        Http::Request request(cmd);
        Http::Response response=API::_poloniexConnexion.sendRequest(request);
        if(response.getStatus()==Http::Response::Ok)
            return response.getBody();
        else
            return "";
    }

    string API::getTicker()
    {
        map<string,string> parameters;
        parameters["command"]="returnTicker";
        return API::requestPublicWebApi(parameters);
    }



}
