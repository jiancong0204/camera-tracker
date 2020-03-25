#include "mqttPublish.h"

void Publish::publishPayload(const char* PAYLOAD, string TOPIC)
{
	string	address = DFLT_SERVER_ADDRESS,
		clientID = DFLT_CLIENT_ID;

	mqtt::async_client client(address, clientID);

	callback cb;
	client.set_callback(cb);

	mqtt::connect_options conopts;
	mqtt::message willmsg(TOPIC, LWT_PAYLOAD, 1, true);
	mqtt::will_options will(willmsg);
	conopts.set_will(will);

	try {
		mqtt::token_ptr conntok = client.connect(conopts);
		conntok->wait();

		mqtt::message_ptr pubmsg = mqtt::make_message(TOPIC, PAYLOAD);
		pubmsg->set_qos(QOS);
		client.publish(pubmsg)->wait_for(TIMEOUT);

		// Double check that there are no pending tokens

		auto toks = client.get_pending_delivery_tokens();
		if (!toks.empty())
			cout << "Error: There are pending delivery tokens!" << endl;

		// Disconnect
		conntok = client.disconnect();
		conntok->wait();
	}
	catch (const mqtt::exception & exc) {
		cerr << exc.what() << endl;
	}
}