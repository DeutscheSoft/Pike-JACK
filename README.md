# Pike module for the JACK audio connection kit

This is an incomplete Pike module for the JACK audio connection kit. It
currently supports manipulation Clients in the JACK graph, sending and
receiving MIDI events.

Due to the nature of JACK, the API is somewhat unusual in comparison
to other Pike APIs. In particular, in order to process incoming MIDI
events from a JACK client, it is necessary to run a dedicated Pike thread
which continuously reads events.

Internally, per JACK client one processing thread will be created, which
passes all data from and to Pike using a ringbuffer. This ringbuffer has
a fixed size and it is therefore important to process incoming MIDI events
fast enough to prevent buffer overruns.

This module requires Pike 8.

# License

This module is licensed under the GPLv2.
