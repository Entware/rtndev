#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=rcon
PKG_VERSION:=0.6
PKG_REV:=14d4e76a9f3659b0f4403d1e0d2f81c0c4995ca2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/n0la/rcon.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk
include $(INCLUDE_DIR)/nls.mk

define Package/rcon
	SECTION:=games
	CATEGORY:=Games
	DEPENDS:=+glib2
	TITLE:=source RCON client
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/rcon/description
 Rcon is a command line application that can be used as a Source RCON client.
 It will send commands to the given server, and print the reply to stdout.
endef

define Package/rcon/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/rcon $(1)/opt/bin
endef

$(eval $(call BuildPackage,rcon))
