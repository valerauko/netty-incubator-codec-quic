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
package io.netty.incubator.codec.quic;

import io.netty.buffer.ByteBuf;
import io.netty.channel.Channel;
import io.netty.channel.ChannelFuture;
import io.netty.channel.ChannelHandler;
import io.netty.channel.ChannelPromise;
import io.netty.util.concurrent.Future;
import io.netty.util.concurrent.Promise;

/**
 * A QUIC {@link Channel}.
 */
public interface QuicChannel extends Channel {

    /**
     * Returns the configuration of this channel.
     */
    @Override
    QuicChannelConfig config();

    /**
     * Creates a stream that is using this {@link QuicChannel} and notifies the {@link Future} once done.
     * The {@link ChannelHandler} (if not {@code null}) is added to the {@link io.netty.channel.ChannelPipeline} of the
     * {@link QuicStreamChannel} automatically.
     */
    default Future<QuicStreamChannel> createStream(QuicStreamType type, ChannelHandler handler) {
        return createStream(type, handler, eventLoop().newPromise());
    }

    /**
     * Creates a stream that is using this {@link QuicChannel} and notifies the {@link Promise} once done.
     * The {@link ChannelHandler} (if not {@code null}) is added to the {@link io.netty.channel.ChannelPipeline} of the
     * {@link QuicStreamChannel} automatically.
     */
    Future<QuicStreamChannel> createStream(QuicStreamType type, ChannelHandler handler,
                                           Promise<QuicStreamChannel> promise);

    /**
     * Returns a new {@link QuicStreamChannelBootstrap} which makes it easy to bootstrap new {@link QuicStreamChannel}s
     * with custom options and attributes. For simpler use-cases you may want to consider using
     * {@link #createStream(QuicStreamType, ChannelHandler)} or
     * {@link #createStream(QuicStreamType, ChannelHandler, Promise)} directly.
     */
    default QuicStreamChannelBootstrap newStreamBootstrap() {
        return new QuicStreamChannelBootstrap(this);
    }

    /**
     * Returns the negotiated ALPN protocol or {@code null} if none has been negotiated.
     */
    byte[] applicationProtocol();

    /**
     * Close the {@link QuicChannel}
     *
     * @param applicationClose  {@code true} if an application close should be used,
     *                          {@code false} if a normal close should be used.
     * @param error             the application error number, or {@code 0} if no special error should be signaled.
     * @param reason            the reason for the closure (which may be an empty {@link ByteBuf}.
     * @return                  the future that is notified.
     */
    default ChannelFuture close(boolean applicationClose, int error, ByteBuf reason) {
        return close(applicationClose, error, reason, newPromise());
    }

    /**
     * Close the {@link QuicChannel}
     *
     * @param applicationClose  {@code true} if an application close should be used,
     *                          {@code false} if a normal close should be used.
     * @param error             the application error number, or {@code 0} if no special error should be signaled.
     * @param reason            the reason for the closure (which may be an empty {@link ByteBuf}.
     * @param promise           the {@link ChannelPromise} that will be notified.
     * @return                  the future that is notified.
     */
    ChannelFuture close(boolean applicationClose, int error, ByteBuf reason, ChannelPromise promise);

    /**
     * Collects statistics about the connection and notifies the {@link Future} once done.
     */
    default Future<QuicConnectionStats> collectStats() {
        return collectStats(eventLoop().newPromise());
    }

    /**
     * Collects statistics about the connection and notifies the {@link Promise} once done.
     */
    Future<QuicConnectionStats> collectStats(Promise<QuicConnectionStats> promise);

    /**
     * Creates a new {@link QuicChannelBootstrap} that can be used to create and connect new {@link QuicChannel}s to
     * endpoints using the given {@link Channel} as transport layer.
     */
    static QuicChannelBootstrap newBootstrap(Channel channel) {
        return new QuicChannelBootstrap(channel);
    }
}
