# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=rtmpdump
PKG_REAL_VERSION:=2.6
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_DATE:=2024-03-01
PKG_SOURCE_VERSION:=6f6bb1353fc84f4cc37138baa99f586750028a01
PKG_SOURCE_URL:=git://git.ffmpeg.org/rtmpdump
PKG_MIRROR_HASH:=e793aa96553b57014492932a40b1d91105589216a4388d22b5e8dfa4733d5929

PKG_VERSION:=$(PKG_REAL_VERSION)_git$(subst -,,$(PKG_SOURCE_DATE))~$(call version_abbrev,$(PKG_SOURCE_VERSION))

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=GPL-2.0-only
PKG_LICENSE_FILES:=COPYING

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/rtmpdump/Default
  TITLE:=a toolkit for RTMP streams
  URL:=https://rtmpdump.mplayerhq.hu/
endef

define Package/librtmp
  $(call Package/rtmpdump/Default)
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE+= (library)
  DEPENDS:=+libgnutls +zlib
endef

define Package/rtmpdump
  $(call Package/rtmpdump/Default)
  SECTION:=net
  CATEGORY:=Network
  DEPENDS:=+librtmp
endef

define Package/librtmp/description
 librtmp is a RTMPDump Real-Time Messaging Protocol API.
endef

define Package/rtmpdump/description
 rtmpdump is a toolkit for RTMP streams. All forms of RTMP are supported.
endef

MAKE_VARS += \
	XCFLAGS="$(TARGET_CFLAGS) -I$(STAGING_DIR)/opt/include" \
	XLDFLAGS="$(TARGET_LDFLAGS)"

MAKE_FLAGS += \
	VERSION=v$(PKG_VERSION) \
	prefix="/opt"

define Package/librtmp/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/librtmp.so* $(1)/opt/lib
endef

define Package/rtmpdump/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/rtmpdump $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/rtmp{gw,srv,suck} $(1)/opt/sbin
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/librtmp $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/librtmp.{a,so*} $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/librtmp.pc $(1)/opt/lib/pkgconfig
	# fix
	$(SED) 's,^libdir=.*,libdir=$$$${exec_prefix}/lib,' \
		$(1)/opt/lib/pkgconfig/librtmp.pc
endef

$(eval $(call BuildPackage,librtmp))
$(eval $(call BuildPackage,rtmpdump))
