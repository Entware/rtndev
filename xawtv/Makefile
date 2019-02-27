#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# This is the last version with V4L1 API support

include $(TOPDIR)/rules.mk

PKG_NAME:=xawtv
PKG_VERSION:=3.105
PKG_RELEASE:=1

PKG_SOURCE:=xawtv-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=http://linuxtv.org/downloads/xawtv
PKG_HASH:=2bd899d8366cd74a59e8e1bc002a41004ab40fbba98184e40c5f42e61b98640f

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/xawtv
	SECTION:=multimedia
	CATEGORY:=Multimedia
	DEPENDS:=+alsa-lib +libncursesw +libv4l +libjpeg
	TITLE:=a small suite of V4L apps
	URL:=https://www.kraxel.org/blog/linux/xawtv
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/xawtv/description
 A small suite of applications for V4L devices.
endef

CONFIGURE_ARGS += \
	--disable-xfree-ext \
	--disable-xvideo \
	--disable-lirc \
	--disable-quicktime \
	--disable-motif \
	--disable-aa \
	--enable-alsa \
	--disable-zvbi \
	--disable-gl \
	--disable-dv \
	--disable-mmx \
	--disable-xft \
	--without-x \

BINARIES = \
	dump-mixers \
	ntsc-cc \
	radio \
	record \
	showqt \
	showriff \
	streamer \
	v4l-conf \
	v4l-info \
	webcam \

define Package/xawtv/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) \
	    $(foreach bin,$(BINARIES),$(PKG_INSTALL_DIR)/opt/bin/$(bin)) \
	    $(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/lib/xawtv
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/xawtv/* $(1)/opt/lib/xawtv
	$(INSTALL_DIR) $(1)/opt/share/xawtv
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/share/xawtv/* $(1)/opt/share/xawtv
endef

$(eval $(call BuildPackage,xawtv))
