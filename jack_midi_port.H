        INIT {
            THIS->client = NULL;
            THIS->port = NULL;
            THIS->rb = jack_ringbuffer_create(1024 * sizeof(struct midi_event));
            THIS->port_handle = NULL;
        }

        EXIT {
            if (THIS->port) jack_port_unregister(THIS->client, THIS->port);
            if (THIS->port_handle) client_remove_port(find_client_struct(), THIS->port_handle);
            if (THIS->rb) jack_ringbuffer_free(THIS->rb);
        }

#cmod_include "jack_port.H"
