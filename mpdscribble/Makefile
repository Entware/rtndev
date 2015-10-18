#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=mpdscribble
PKG_VERSION:=0.23-20140213
PKG_REV:=979e96a50f12506420bbc65c409d00cb709e7c9e
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=git://git.musicpd.org/master/mpdscribble.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/mpdscribble
	SECTION:=sound
	CATEGORY:=Sound
	DEPENDS:=+libmpdclient +libsoup +libcurl
	TITLE:=MPD player with Last.fm scrobbler
	URL:=http://mpd.wikia.com/wiki/Client:Mpdscribble
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/mpdscribble/description
 MPD scribble is a music player daemon client which submits information about
 tracks being played to Last.fm.
endef

TARGET_CFLAGS += \
	-std=gnu99

define Package/mpdscribble/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/mpdscribble $(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/etc/mpdscribble.conf $(1)/opt/etc/
endef

define Package/mpdscribble/conffiles
/opt/etc/mpdscribble.conf
endef

$(eval $(call BuildPackage,mpdscribble))
