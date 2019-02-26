#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=portspoof
PKG_VERSION:=1.3
PKG_REV:=70b6bf2ad96b0824ae6e2c2cea4c59d2a156d2c1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/drk1wi/portspoof
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/portspoof
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libstdcpp +libpthread
	TITLE:=effective defense against port scanners
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/portspoof/description
 The Portspoof program primary goal is to enhance OS security through a set of
 few techniques: all TCP ports are always open, every open TCP port emulates
 a services. Portspoof can be used as an 'Exploitation Framework Frontend',
 that turns your system into responsive and aggressive machine.
endef

define Package/portspoof/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/portspoof $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_CONF) \
	    $(PKG_INSTALL_DIR)/opt/etc/portspoof{.conf,_signatures} $(1)/opt/etc
endef

$(eval $(call BuildPackage,portspoof))
