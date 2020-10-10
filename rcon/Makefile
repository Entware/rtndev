#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=rcon
PKG_VERSION:=0.5
PKG_REV:=a3470a35f23466f85f01c00cd63e147c8d3f036c
PKG_RELEASE:=2

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
