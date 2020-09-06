#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=mpdscribble
PKG_VERSION:=0.23-20191206
PKG_REV:=048bc62e43a6000f99291522b725f1ddd48864c1
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/MusicPlayerDaemon/mpdscribble.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_INSTALL:=1

PKG_BUILD_DEPENDS:=meson/host boost

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/devel/meson/meson.mk

define Package/mpdscribble
	SECTION:=sound
	CATEGORY:=Sound
	DEPENDS:=+libgcrypt +libmpdclient +libcurl +libstdcpp
	TITLE:=MPD player with Last.fm scrobbler
	URL:=http://mpd.wikia.com/wiki/Client:Mpdscribble
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/mpdscribble/description
 MPD scribble is a music player daemon client which submits information about
 tracks being played to Last.fm.
endef

MESON_ARGS += \
	-Dsystemd=disabled

MESON_VARS+=BOOST_ROOT=$(STAGING_DIR)/opt

TARGET_CFLAGS += $(shell $(STAGING_DIR)/opt/bin/libgcrypt-config --cflags)
TARGET_LDFLAGS += $(shell $(STAGING_DIR)/opt/bin/libgcrypt-config --libs)

define Package/mpdscribble/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/mpdscribble $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/opt/etc/mpdscribble.conf $(1)/opt/etc
endef

define Package/mpdscribble/conffiles
/opt/etc/mpdscribble.conf
endef

$(eval $(call BuildPackage,mpdscribble))
