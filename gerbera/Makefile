#
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=gerbera
PKG_VERSION:=1.1
PKG_REV:=2b2a13d2476f59e4dab88d2e2464ed2a6d081b23
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/v00d00/gerbera.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/gerbera
	SECTION:=multimedia
	CATEGORY:=Multimedia
	DEPENDS:=+libffmpeg-full +duktape +libupnp-1.8 +libsqlite3 +libcurl \
	    +libtheora +file +libexif +libexpat +libvorbis +libuuid +libstdcpp
	TITLE:=a free media server
	URL:=https://gerbera.io
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/gerbera/description
 UPnP Media Server for 2017 (Based on MediaTomb)
endef

CMAKE_OPTIONS += \
	-DWITH_MYSQL=0 \
	-DWITH_TAGLIB=0 \
	-DWITH_AVCODEC=1 \
	-DWITH_DEBUG_LOGGING=0 \
	-DWITH_SYSTEMD=0

define Package/gerbera/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/$(PKG_NAME) $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/share
	$(CP) $(PKG_INSTALL_DIR)/opt/share/$(PKG_NAME) $(1)/opt/share
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) files/S90$(PKG_NAME) $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/etc/$(PKG_NAME)
endef

$(eval $(call BuildPackage,gerbera))
