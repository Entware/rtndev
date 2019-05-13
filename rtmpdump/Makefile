#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=rtmpdump
PKG_VERSION:=2.4-20190330
PKG_REV:=c5f04a58fc2aeea6296ca7c44ee4734c18401aa3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=git://git.ffmpeg.org/rtmpdump
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/rtmpdump/Default
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libgnutls +zlib
	TITLE:=rtmpdump is a toolkit for RTMP streams
	URL:=http://rtmpdump.mplayerhq.hu/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/librtmp
	$(call Package/rtmpdump/Default)
endef

define Package/rtmpdump
	$(call Package/rtmpdump/Default)
	DEPENDS:= +librtmp
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
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/librtmp.so.1 $(1)/opt/lib
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
