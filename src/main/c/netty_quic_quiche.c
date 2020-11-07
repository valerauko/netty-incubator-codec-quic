/*
 * Copyright 2020 The Netty Project
 *
 * The Netty Project licenses this file to you under the Apache License,
 * version 2.0 (the "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at:
 *
 *   https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */
#include <jni.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <quiche.h>
#include "netty_jni_util.h"

// Add define if NETTY_BUILD_STATIC is defined so it is picked up in netty_jni_util.c
#ifdef NETTY_BUILD_STATIC
#define NETTY_JNI_UTIL_BUILD_STATIC
#endif

#define STATICALLY_CLASSNAME "io/netty/incubator/codec/quic/NativeStaticallyReferencedJniMethods"
#define QUICHE_CLASSNAME "io/netty/incubator/codec/quic/Quiche"

static jint netty_quic_quiche_max_conn_id_len(JNIEnv* env, jclass clazz) {
    return QUICHE_MAX_CONN_ID_LEN;
}

static jint netty_quic_quiche_protocol_version(JNIEnv* env, jclass clazz) {
    return QUICHE_PROTOCOL_VERSION;
}

static jint netty_quic_quiche_shutdown_read(JNIEnv* env, jclass clazz) {
    return QUICHE_SHUTDOWN_READ;
}

static jint netty_quic_quiche_shutdown_write(JNIEnv* env, jclass clazz) {
    return QUICHE_SHUTDOWN_WRITE;
}

static jint netty_quic_quiche_err_done(JNIEnv* env, jclass clazz) {
    return QUICHE_ERR_DONE;
}

static jint netty_quic_quiche_err_buffer_too_short(JNIEnv* env, jclass clazz) {
    return QUICHE_ERR_BUFFER_TOO_SHORT;
}

static jint netty_quic_quiche_err_unknown_version(JNIEnv* env, jclass clazz) {
    return QUICHE_ERR_UNKNOWN_VERSION;
}

static jint netty_quic_quiche_err_invalid_frame(JNIEnv* env, jclass clazz) {
    return QUICHE_ERR_INVALID_FRAME;
}

static jint netty_quic_quiche_err_invalid_packet(JNIEnv* env, jclass clazz) {
    return QUICHE_ERR_INVALID_PACKET;
}

static jint netty_quic_quiche_err_invalid_state(JNIEnv* env, jclass clazz) {
    return QUICHE_ERR_INVALID_STATE;
}

static jint netty_quic_quiche_err_invalid_stream_state(JNIEnv* env, jclass clazz) {
    return QUICHE_ERR_INVALID_STREAM_STATE;
}

static jint netty_quic_quiche_err_invalid_transport_param(JNIEnv* env, jclass clazz) {
    return QUICHE_ERR_INVALID_TRANSPORT_PARAM;
}

static jint netty_quic_quiche_err_crypto_fail(JNIEnv* env, jclass clazz) {
    return QUICHE_ERR_CRYPTO_FAIL;
}

static jint netty_quic_quiche_err_tls_fail(JNIEnv* env, jclass clazz) {
    return QUICHE_ERR_TLS_FAIL;
}

static jint netty_quic_quiche_err_flow_control(JNIEnv* env, jclass clazz) {
    return QUICHE_ERR_FLOW_CONTROL;
}

static jint netty_quic_quiche_err_stream_limit(JNIEnv* env, jclass clazz) {
    return QUICHE_ERR_STREAM_LIMIT;
}

static jint netty_quic_quiche_err_final_size(JNIEnv* env, jclass clazz) {
    return QUICHE_ERR_FINAL_SIZE;
}

static jint netty_quic_quiche_err_congestion_control(JNIEnv* env, jclass clazz) {
    return QUICHE_ERR_CONGESTION_CONTROL;
}

static jint netty_quic_quiche_cc_reno(JNIEnv* env, jclass clazz) {
    return QUICHE_CC_RENO;
}

static jint netty_quic_quiche_cc_cubic(JNIEnv* env, jclass clazz) {
    return QUICHE_CC_CUBIC;
}

static jstring netty_quic_quiche_version(JNIEnv* env, jclass clazz) {
    return (*env)->NewStringUTF(env, quiche_version());
}

static jboolean netty_quic_quiche_version_is_supported(JNIEnv* env, jclass clazz, jint version) {
    return quiche_version_is_supported(version) == true ? JNI_TRUE : JNI_FALSE;
}

static jint netty_quic_quiche_header_info(JNIEnv* env, jclass clazz, jlong buf, jint buf_len, jint dcil, jlong version,
                 jlong type, jlong scid, jlong scid_len, jlong dcid, jlong dcid_len, jlong token, jlong token_len) {
    return (jint) quiche_header_info((const uint8_t *) buf, (size_t) buf_len, (size_t) dcil,
                                         (uint32_t *) version, (uint8_t *) type,
                                         (uint8_t *) scid, (size_t *) scid_len,
                                         (uint8_t *) dcid, (size_t *) dcid_len,
                                         (uint8_t *) token, (size_t *) token_len);
}

static jint netty_quic_quiche_negotiate_version(JNIEnv* env, jclass clazz, jlong scid, jint scid_len, jlong dcid, jint dcid_len, jlong out, jint out_len) {
    return (jint) quiche_negotiate_version((const uint8_t *) scid, (size_t) scid_len,
                                                   (const uint8_t *) dcid, (size_t) dcid_len,
                                                   (uint8_t *)out, (size_t) out_len);
}

static jint netty_quic_quiche_retry(JNIEnv* env, jclass clazz, jlong scid, jint scid_len, jlong dcid, jint dcid_len,
                jlong new_scid, jint new_scid_len, jlong token, jint token_len, jint version, jlong out, jint out_len) {
    return (jint) quiche_retry((const uint8_t *) scid, (size_t) scid_len,
                               (const uint8_t *) dcid, (size_t) dcid_len,
                               (const uint8_t *) new_scid, (size_t) new_scid_len,
                               (const uint8_t *) token, (size_t) token_len,
                               (uint32_t) version, (uint8_t *) out, (size_t) out_len);
}

static jlong netty_quic_quiche_accept(JNIEnv* env, jclass clazz, jlong scid, jint scid_len, jlong odcid, jint odcid_len, jlong config) {
    return (jlong) quiche_accept((const uint8_t *) scid, (size_t) scid_len,
                                 (const uint8_t *) odcid, (size_t) odcid_len,
                                 (quiche_config *) config);
}

static jint netty_quic_quiche_conn_recv(JNIEnv* env, jclass clazz, jlong conn, jlong buf, jint buf_len) {
    return (jint) quiche_conn_recv((quiche_conn *) conn, (uint8_t *) buf, (size_t) buf_len);
}

static jint netty_quic_quiche_conn_send(JNIEnv* env, jclass clazz, jlong conn, jlong out, jint out_len) {
    return (jint) quiche_conn_send((quiche_conn *) conn, (uint8_t *) out, (size_t) out_len);
}

static void netty_quic_quiche_conn_free(JNIEnv* env, jclass clazz, jlong conn) {
    quiche_conn_free((quiche_conn *) conn);
}

static jlong netty_quic_quiche_connect(JNIEnv* env, jclass clazz, jstring server_name, jlong scid, jint scid_len, jlong config) {
    const char *name = (*env)->GetStringUTFChars(env, server_name, 0);
    if (name == NULL) {
        return -1;
    }
    quiche_conn *conn = quiche_connect(name, (const uint8_t *) scid, (size_t) scid_len, (quiche_config *) config);
    (*env)->ReleaseStringUTFChars(env, server_name, name);
    if (conn == NULL) {
        return -1;
    }
    return (jlong) conn;
}

static jint netty_quic_quiche_conn_stream_recv(JNIEnv* env, jclass clazz, jlong conn, jlong stream_id, jlong out, int buf_len, jlong finAddr) {
    return (jint) quiche_conn_stream_recv((quiche_conn *) conn, (uint64_t) stream_id,  (uint8_t *) out, (size_t) buf_len, (bool *) finAddr);
}

static jint netty_quic_quiche_conn_stream_send(JNIEnv* env, jclass clazz, jlong conn, jlong stream_id, jlong buf, int buf_len, jboolean fin) {
    return (jint) quiche_conn_stream_send((quiche_conn *) conn, (uint64_t) stream_id,  (uint8_t *) buf, (size_t) buf_len, fin == JNI_TRUE ? true : false);
}

static jint netty_quic_quiche_conn_stream_shutdown(JNIEnv* env, jclass clazz, jlong conn, jlong stream_id, jint direction, jlong err) {
    return (jint) quiche_conn_stream_shutdown((quiche_conn *) conn, (uint64_t) stream_id,  (enum quiche_shutdown) direction, (uint64_t) err);
}

static jint netty_quic_quiche_conn_stream_capacity(JNIEnv* env, jclass clazz, jlong conn, jlong stream_id) {
    return (jint) quiche_conn_stream_capacity((quiche_conn *) conn, (uint64_t) stream_id);
}

static jboolean netty_quic_quiche_conn_stream_finished(JNIEnv* env, jclass clazz, jlong conn, jlong stream_id) {
    return quiche_conn_stream_finished((quiche_conn *) conn, (uint64_t) stream_id) == true ? JNI_TRUE : JNI_FALSE;
}

static jint netty_quic_quiche_conn_close(JNIEnv* env, jclass clazz, jlong conn, jboolean app, jlong err, jlong reason, jint reason_len) {
    return quiche_conn_close((quiche_conn *) conn, app == JNI_TRUE ? true : false, err, (const uint8_t *) reason, (size_t) reason_len);
}

static jboolean netty_quic_quiche_conn_is_established(JNIEnv* env, jclass clazz, jlong conn) {
    return quiche_conn_is_established((quiche_conn *) conn) == true ? JNI_TRUE : JNI_FALSE;
}

static jboolean netty_quic_quiche_conn_is_in_early_data(JNIEnv* env, jclass clazz, jlong conn) {
    return quiche_conn_is_in_early_data((quiche_conn *) conn) == true ? JNI_TRUE : JNI_FALSE;
}

static jboolean netty_quic_quiche_conn_is_closed(JNIEnv* env, jclass clazz, jlong conn) {
    return quiche_conn_is_closed((quiche_conn *) conn) == true ? JNI_TRUE : JNI_FALSE;
}

static jlong netty_quic_quiche_conn_timeout_as_nanos(JNIEnv* env, jclass clazz, jlong conn) {
    return quiche_conn_timeout_as_nanos((quiche_conn *) conn);
}

static jlong netty_quic_quiche_conn_timeout_as_millis(JNIEnv* env, jclass clazz, jlong conn) {
    return quiche_conn_timeout_as_millis((quiche_conn *) conn);
}

static void netty_quic_quiche_conn_on_timeout(JNIEnv* env, jclass clazz, jlong conn) {
    quiche_conn_on_timeout((quiche_conn *) conn);
}

static int transfer_to_array_and_free(JNIEnv* env, quiche_stream_iter* iter, jlongArray streams) {
    int len = (*env)->GetArrayLength(env, streams);
    int i = 0;
    uint64_t stream_id = 0;

    while (quiche_stream_iter_next(iter, &stream_id) && i < len) {
        (*env)->SetLongArrayRegion(env, streams, i++, 1, (jlong*) &stream_id);
    }
    quiche_stream_iter_free(iter);
    return i;
}

static int netty_quic_quiche_conn_readable(JNIEnv* env, jclass clazz, jlong conn, jlongArray readableStreams) {
    return transfer_to_array_and_free(env, quiche_conn_readable((quiche_conn *) conn), readableStreams);
}

static int netty_quic_quiche_conn_writable(JNIEnv* env, jclass clazz, jlong conn, jlongArray writableStreams) {
    return transfer_to_array_and_free(env, quiche_conn_writable((quiche_conn *) conn), writableStreams);
}

static jlong netty_quic_quiche_config_new(JNIEnv* env, jclass clazz, jint version) {
    quiche_config* config = quiche_config_new((uint32_t) version);
    return config == NULL ? -1 : (jlong) config;
}

static jint netty_quic_quiche_config_load_cert_chain_from_pem_file(JNIEnv* env, jclass clazz, jlong config, jstring path) {
    const char *p = (*env)->GetStringUTFChars(env, path, 0);
    if (p == NULL) {
        return -1;
    }
    int res = quiche_config_load_cert_chain_from_pem_file((quiche_config*) config, p);
    (*env)->ReleaseStringUTFChars(env, path, p);
    return res;
}

static jint netty_quic_quiche_config_load_priv_key_from_pem_file(JNIEnv* env, jclass clazz, jlong config, jstring path) {
    const char *p = (*env)->GetStringUTFChars(env, path, 0);
    if (p == NULL) {
        return -1;
    }
    int res = quiche_config_load_priv_key_from_pem_file((quiche_config*) config, p);
    (*env)->ReleaseStringUTFChars(env, path, p);
    return res;
}

static void netty_quic_quiche_config_verify_peer(JNIEnv* env, jclass clazz, jlong config, jboolean value) {
    quiche_config_verify_peer((quiche_config*) config, value == JNI_TRUE ? true : false);
}

static void netty_quic_quiche_config_grease(JNIEnv* env, jclass clazz, jlong config, jboolean value) {
    quiche_config_grease((quiche_config*) config, value == JNI_TRUE ? true : false);
}

static void netty_quic_quiche_config_enable_early_data(JNIEnv* env, jclass clazz, jlong config) {
    quiche_config_enable_early_data((quiche_config*) config);
}

static jint netty_quic_quiche_config_set_application_protos(JNIEnv* env, jclass clazz, jlong config, jbyteArray protos) {
    size_t len = (*env)->GetArrayLength(env, protos);
    uint8_t *p = (uint8_t *) malloc(sizeof(uint8_t) * len);
    (*env)->GetByteArrayRegion(env, protos, 0, len, (jbyte *) p);
    int res = quiche_config_set_application_protos((quiche_config*) config, p, len);
    free(p);
    return res;
}

static void netty_quic_quiche_config_set_max_idle_timeout(JNIEnv* env, jclass clazz, jlong config, jlong value) {
    quiche_config_set_max_idle_timeout((quiche_config*) config, (uint64_t) value);
}

static void netty_quic_quiche_config_set_max_udp_payload_size(JNIEnv* env, jclass clazz, jlong config, jlong value) {
    quiche_config_set_max_udp_payload_size((quiche_config*) config, (uint64_t) value);
}

static void netty_quic_quiche_config_set_initial_max_data(JNIEnv* env, jclass clazz, jlong config, jlong value) {
    quiche_config_set_initial_max_data((quiche_config*) config, (uint64_t) value);
}

static void netty_quic_quiche_config_set_initial_max_stream_data_bidi_local(JNIEnv* env, jclass clazz, jlong config, jlong value) {
    quiche_config_set_initial_max_stream_data_bidi_local((quiche_config*) config, (uint64_t) value);
}

static void netty_quic_quiche_config_set_initial_max_stream_data_bidi_remote(JNIEnv* env, jclass clazz, jlong config, jlong value) {
    quiche_config_set_initial_max_stream_data_bidi_remote((quiche_config*) config, (uint64_t) value);
}

static void netty_quic_quiche_config_set_initial_max_stream_data_uni(JNIEnv* env, jclass clazz, jlong config, jlong value) {
    quiche_config_set_initial_max_stream_data_uni((quiche_config*) config, (uint64_t) value);
}

static void netty_quic_quiche_config_set_initial_max_streams_bidi(JNIEnv* env, jclass clazz, jlong config, jlong value) {
    quiche_config_set_initial_max_streams_bidi((quiche_config*) config, (uint64_t) value);
}

static void netty_quic_quiche_config_set_initial_max_streams_uni(JNIEnv* env, jclass clazz, jlong config, jlong value) {
    quiche_config_set_initial_max_streams_uni((quiche_config*) config, (uint64_t) value);
}

static void netty_quic_quiche_config_set_ack_delay_exponent(JNIEnv* env, jclass clazz, jlong config, jlong value) {
    quiche_config_set_ack_delay_exponent((quiche_config*) config, (uint64_t) value);
}

static void netty_quic_quiche_config_set_max_ack_delay(JNIEnv* env, jclass clazz, jlong config, jlong value) {
    quiche_config_set_max_ack_delay((quiche_config*) config, (uint64_t) value);
}

static void netty_quic_quiche_config_set_disable_active_migration(JNIEnv* env, jclass clazz, jlong config, jboolean value) {
    quiche_config_set_disable_active_migration((quiche_config*) config, value == JNI_TRUE ? true : false);
}

static void netty_quic_quiche_config_set_cc_algorithm(JNIEnv* env, jclass clazz, jlong config, jint algo) {
    quiche_config_set_cc_algorithm((quiche_config*) config, (enum quiche_cc_algorithm) algo);
}

static void netty_quic_quiche_config_enable_hystart(JNIEnv* env, jclass clazz, jlong config, jboolean value) {
    quiche_config_enable_hystart((quiche_config*) config, value == JNI_TRUE ? true : false);
}

static void netty_quic_quiche_config_free(JNIEnv* env, jclass clazz, jlong config) {
    quiche_config_free((quiche_config*) config);
}

// JNI Registered Methods End

// JNI Method Registration Table Begin
static const JNINativeMethod statically_referenced_fixed_method_table[] = {
  { "quiche_protocol_version", "()I", (void *) netty_quic_quiche_protocol_version },
  { "quiche_max_conn_id_len", "()I", (void *) netty_quic_quiche_max_conn_id_len },
  { "quiche_shutdown_read", "()I", (void *) netty_quic_quiche_shutdown_read },
  { "quiche_shutdown_write", "()I", (void *) netty_quic_quiche_shutdown_write },
  { "quiche_err_done", "()I", (void *) netty_quic_quiche_err_done },
  { "quiche_err_buffer_too_short", "()I", (void *) netty_quic_quiche_err_buffer_too_short },
  { "quiche_err_unknown_version", "()I", (void *) netty_quic_quiche_err_unknown_version },
  { "quiche_err_invalid_frame", "()I", (void *) netty_quic_quiche_err_invalid_frame },
  { "quiche_err_invalid_packet", "()I", (void *) netty_quic_quiche_err_invalid_packet },
  { "quiche_err_invalid_state", "()I", (void *) netty_quic_quiche_err_invalid_state },
  { "quiche_err_invalid_stream_state", "()I", (void *) netty_quic_quiche_err_invalid_stream_state },
  { "quiche_err_invalid_transport_param", "()I", (void *) netty_quic_quiche_err_invalid_transport_param },
  { "quiche_err_crypto_fail", "()I", (void *) netty_quic_quiche_err_crypto_fail },
  { "quiche_err_tls_fail", "()I", (void *) netty_quic_quiche_err_tls_fail },
  { "quiche_err_flow_control", "()I", (void *) netty_quic_quiche_err_flow_control },
  { "quiche_err_stream_limit", "()I", (void *) netty_quic_quiche_err_stream_limit },
  { "quiche_err_final_size", "()I", (void *) netty_quic_quiche_err_final_size },
  { "quiche_err_congestion_control", "()I", (void *) netty_quic_quiche_err_congestion_control },
  { "quiche_cc_reno", "()I", (void *) netty_quic_quiche_cc_reno },
  { "quiche_cc_cubic", "()I", (void *) netty_quic_quiche_cc_cubic }
};

static const jint statically_referenced_fixed_method_table_size = sizeof(statically_referenced_fixed_method_table) / sizeof(statically_referenced_fixed_method_table[0]);
static const JNINativeMethod fixed_method_table[] = {
  { "quiche_version", "()Ljava/lang/String;", (void *) netty_quic_quiche_version },
  { "quiche_version_is_supported", "(I)Z", (void *) netty_quic_quiche_version_is_supported },
  { "quiche_header_info", "(JIIJJJJJJJJ)I", (void *) netty_quic_quiche_header_info },
  { "quiche_negotiate_version", "(JIJIJI)I", (void *) netty_quic_quiche_negotiate_version },
  { "quiche_retry", "(JIJIJIJIIJI)I", (void *) netty_quic_quiche_retry },
  { "quiche_accept", "(JIJIJ)J", (void *) netty_quic_quiche_accept },
  { "quiche_conn_recv", "(JJI)I", (void *) netty_quic_quiche_conn_recv },
  { "quiche_conn_send", "(JJI)I", (void *) netty_quic_quiche_conn_send },
  { "quiche_conn_free", "(J)V", (void *) netty_quic_quiche_conn_free },
  { "quiche_connect", "(Ljava/lang/String;JIJ)J", (void *) netty_quic_quiche_connect },
  { "quiche_conn_stream_recv", "(JJJIJ)I", (void *) netty_quic_quiche_conn_stream_recv },
  { "quiche_conn_stream_send", "(JJJIZ)I", (void *) netty_quic_quiche_conn_stream_send },
  { "quiche_conn_stream_shutdown", "(JJIJ)I", (void *) netty_quic_quiche_conn_stream_shutdown },
  { "quiche_conn_stream_capacity", "(JJ)I", (void *) netty_quic_quiche_conn_stream_capacity },
  { "quiche_conn_stream_finished", "(JJ)Z", (void *) netty_quic_quiche_conn_stream_finished },
  { "quiche_conn_close", "(JZJJI)I", (void *) netty_quic_quiche_conn_close },
  { "quiche_conn_is_established", "(J)Z", (void *) netty_quic_quiche_conn_is_established },
  { "quiche_conn_is_in_early_data", "(J)Z", (void *) netty_quic_quiche_conn_is_in_early_data },
  { "quiche_conn_is_closed", "(J)Z", (void *) netty_quic_quiche_conn_is_closed },
  { "quiche_conn_timeout_as_nanos", "(J)J", (void *) netty_quic_quiche_conn_timeout_as_nanos },
  { "quiche_conn_timeout_as_millis", "(J)J", (void *) netty_quic_quiche_conn_timeout_as_millis },
  { "quiche_conn_on_timeout", "(J)V", (void *) netty_quic_quiche_conn_on_timeout },
  { "quiche_conn_readable", "(J[J)I", (void *) netty_quic_quiche_conn_readable },
  { "quiche_conn_writable", "(J[J)I", (void *) netty_quic_quiche_conn_writable },
  { "quiche_config_new", "(I)J", (void *) netty_quic_quiche_config_new },
  { "quiche_config_load_cert_chain_from_pem_file", "(JLjava/lang/String;)I", (void *) netty_quic_quiche_config_load_cert_chain_from_pem_file },
  { "quiche_config_load_priv_key_from_pem_file", "(JLjava/lang/String;)I", (void *) netty_quic_quiche_config_load_priv_key_from_pem_file },
  { "quiche_config_verify_peer", "(JZ)V", (void *) netty_quic_quiche_config_verify_peer },
  { "quiche_config_grease", "(JZ)V", (void *) netty_quic_quiche_config_grease },
  { "quiche_config_enable_early_data", "(J)V", (void *) netty_quic_quiche_config_enable_early_data },
  { "quiche_config_set_application_protos", "(J[B)I", (void *) netty_quic_quiche_config_set_application_protos },
  { "quiche_config_set_max_idle_timeout", "(JJ)V", (void *) netty_quic_quiche_config_set_max_idle_timeout },
  { "quiche_config_set_max_udp_payload_size", "(JJ)V", (void *) netty_quic_quiche_config_set_max_udp_payload_size },
  { "quiche_config_set_initial_max_data", "(JJ)V", (void *) netty_quic_quiche_config_set_initial_max_data },
  { "quiche_config_set_initial_max_stream_data_bidi_local", "(JJ)V", (void *) netty_quic_quiche_config_set_initial_max_stream_data_bidi_local },
  { "quiche_config_set_initial_max_stream_data_bidi_remote", "(JJ)V", (void *) netty_quic_quiche_config_set_initial_max_stream_data_bidi_remote },
  { "quiche_config_set_initial_max_stream_data_uni", "(JJ)V", (void *) netty_quic_quiche_config_set_initial_max_stream_data_uni },
  { "quiche_config_set_initial_max_streams_bidi", "(JJ)V", (void *) netty_quic_quiche_config_set_initial_max_streams_bidi },
  { "quiche_config_set_initial_max_streams_uni", "(JJ)V", (void *) netty_quic_quiche_config_set_initial_max_streams_uni },
  { "quiche_config_set_ack_delay_exponent", "(JJ)V", (void *) netty_quic_quiche_config_set_ack_delay_exponent },
  { "quiche_config_set_max_ack_delay", "(JJ)V", (void *) netty_quic_quiche_config_set_max_ack_delay },
  { "quiche_config_set_disable_active_migration", "(JZ)V", (void *) netty_quic_quiche_config_set_disable_active_migration },
  { "quiche_config_set_cc_algorithm", "(JI)V", (void *) netty_quic_quiche_config_set_cc_algorithm },
  { "quiche_config_enable_hystart", "(JZ)V", (void *) netty_quic_quiche_config_enable_hystart },
  { "quiche_config_free", "(J)V", (void *) netty_quic_quiche_config_free }
};

static const jint fixed_method_table_size = sizeof(fixed_method_table) / sizeof(fixed_method_table[0]);

// JNI Method Registration Table End

static jint netty_quic_quiche_JNI_OnLoad(JNIEnv* env, const char* packagePrefix) {
    int ret = JNI_ERR;
    int staticallyRegistered = 0;
    int nativeRegistered = 0;

    // We must register the statically referenced methods first!
    if (netty_jni_util_register_natives(env,
            packagePrefix,
            STATICALLY_CLASSNAME,
            statically_referenced_fixed_method_table,
            statically_referenced_fixed_method_table_size) != 0) {
        goto done;
    }
    staticallyRegistered = 1;

    if (netty_jni_util_register_natives(env,
            packagePrefix,
            QUICHE_CLASSNAME,
            fixed_method_table,
            fixed_method_table_size) != 0) {
        goto done;
    }
    nativeRegistered = 1;

    // Initialize this module

    ret = NETTY_JNI_UTIL_JNI_VERSION;
done:

    if (ret == JNI_ERR) {
        if (staticallyRegistered == 1) {
            netty_jni_util_unregister_natives(env, packagePrefix, STATICALLY_CLASSNAME);
        }
        if (nativeRegistered == 1) {
            netty_jni_util_unregister_natives(env, packagePrefix, QUICHE_CLASSNAME);
        }
    }
    return ret;
}

static void netty_quic_quiche_JNI_OnUnload(JNIEnv* env, const char* packagePrefix) {
    netty_jni_util_unregister_natives(env, packagePrefix, STATICALLY_CLASSNAME);
    netty_jni_util_unregister_natives(env, packagePrefix, QUICHE_CLASSNAME);
}

// Invoked by the JVM when statically linked

// We build with -fvisibility=hidden so ensure we mark everything that needs to be visible with JNIEXPORT
// https://mail.openjdk.java.net/pipermail/core-libs-dev/2013-February/014549.html

// Invoked by the JVM when statically linked
JNIEXPORT jint JNI_OnLoad_netty_quic_quiche(JavaVM* vm, void* reserved) {
    return netty_jni_util_JNI_OnLoad(vm, reserved, "netty_quic_quiche", netty_quic_quiche_JNI_OnLoad);
}

// Invoked by the JVM when statically linked
JNIEXPORT void JNI_OnUnload_netty_quic_quiche_JNI_OnLoad(JavaVM* vm, void* reserved) {
    netty_jni_util_JNI_OnUnload(vm, reserved, netty_quic_quiche_JNI_OnUnload);
}

#ifndef NETTY_BUILD_STATIC
JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    return netty_jni_util_JNI_OnLoad(vm, reserved, "netty_quic_quiche", netty_quic_quiche_JNI_OnLoad);
}

JNIEXPORT void JNI_OnUnload(JavaVM* vm, void* reserved) {
    netty_jni_util_JNI_OnUnload(vm, reserved, netty_quic_quiche_JNI_OnUnload);
}
#endif /* NETTY_BUILD_STATIC */