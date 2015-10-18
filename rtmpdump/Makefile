#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=rtmpdump
PKG_VERSION:=2.4-20121209
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-2.3.tgz
PKG_SOURCE_URL:=http://rtmpdump.mplayerhq.hu/download
PKG_MD5SUM:=eb961f31cd55f0acf5aad1a7b900ef59

PKG_INSTALL:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-2.3

include $(INCLUDE_DIR)/package.mk

define Package/rtmpdump/Default
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+zlib +libopenssl +libpthread
	TITLE:=rtmpdump is a toolkit for RTMP streams
	URL:=http://rtmpdump.mplayerhq.hu/
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/librtmp
	$(call Package/rtmpdump/Default)
endef

define Package/rtmpdump
	$(call Package/rtmpdump/Default)
	DEPENDS+= +librtmp
endef

define Package/librtmp/description
 librtmp is a RTMPDump Real-Time Messaging Protocol API
endef

define Package/rtmpdump/description
 rtmpdump is a toolkit for RTMP streams. All forms of RTMP are supported.
endef

MAKE_VARS += \
	XCFLAGS="$(TARGET_CFLAGS) -I$(STAGING_DIR)/opt/include" \
	XLDFLAGS="$(TARGET_LDFLAGS)" \

MAKE_FLAGS += \
	prefix="/opt" \

define Package/librtmp/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/librtmp.so.0 $(1)/opt/lib
	$(LN) librtmp.so.0 $(1)/opt/lib/librtmp.so
endef

define Package/rtmpdump/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/rtmpdump $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/rtmp{gw,srv,suck} $(1)/opt/sbin
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/librtmp.* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/librtmp.pc $(1)/opt/lib/pkgconfig
	$(INSTALL_DIR) $(1)/opt/include/librtmp
	$(CP) $(PKG_INSTALL_DIR)/opt/include/librtmp/*.h $(1)/opt/include/librtmp
endef

$(eval $(call BuildPackage,librtmp))
$(eval $(call BuildPackage,rtmpdump))
