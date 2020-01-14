#ifndef CLICK_PQSCHEDQUEUE_HH
#define CLICK_PQSCHEDQUEUE_HH
#include <click/element.hh>
#include <click/gaprate.hh>
#include <click/glue.hh>
#include "queue.hh"
#include "addlabelheader.hh"
CLICK_DECLS


class PQSchedQueue : public Element {

  public:


    bool _rate_limited;
    GapRate _rate;

    PQSchedQueue();
    ~PQSchedQueue();

    const char *class_name() const		{ return "PQSchedQueue"; }
    const char *port_count() const		{ return "2/1"; }
    const char *processing() const		{ return "h/lh"; }

    int configure(Vector<String> &, ErrorHandler *);

    void push(int port, Packet*);
    Packet* pull(int port);

  private:


	Queue _qqq[8];

};


CLICK_ENDDECLS
#endif
