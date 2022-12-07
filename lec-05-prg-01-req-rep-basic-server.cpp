#include <zmq.hpp>
#include <iostream>
#include <string>
int main(){
    zmq::context_t context(1);

    zmq::socket_t socket(context, ZMQ_REP);
    socket.bind("tcp://*:5555");

    while (true)
    {
        zmq::message_t request;

        socket.recv(request, zmq::recv_flags::none);
        // socket.recv(&request);
        std::cout << "Received request: " << request.to_string() << std::endl;

        zmq_sleep(1);

        socket.send(zmq::str_buffer("b'World"), zmq::send_flags::none);
    }

    return 0;
}


