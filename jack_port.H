        PIKEFUN string(8bit) name() {
            const char *name = jack_port_name(THIS->port);
            if (name) {
                push_text(name);
            } else push_undefined();
        }

        PIKEFUN void connect_to(string(8bit) source) {
            const char *dst = jack_port_name(THIS->port);
            int err;

            err = jack_connect(THIS->client, source->str, dst);

            if (err && err != EEXIST)
                Pike_error("Connecting failed.\n");
        }

        PIKEFUN void disconnect_from(string(8bit) source) {
            const char *dst = jack_port_name(THIS->port);
            int err;

            err = jack_disconnect(THIS->client, source->str, dst);

            if (err) Pike_error("Disconnecting failed.\n");
        }

        PIKEFUN array(string) get_connections() {
            const char **con;
            size_t i = 0;

            /* TODO: this could happen statically */
            if (jack_port_is_mine(THIS->client, THIS->port)) {
                con = jack_port_get_connections(THIS->port);
            } else {
                con = jack_port_get_all_connections(THIS->client, THIS->port);
            }

            if (con) {
                for (; con[i]; i++) {
                    push_text(con[i]);
                }

                jack_free(con);
            }

            f_aggregate(i);
        }
