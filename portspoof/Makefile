#
# Copyright (C) 2011-2026 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=portspoof
PKG_VERSION:=2.0
PKG_REV:=c5063e7d9ac03a65d7c9819dc5bb06869014671a
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/drk1wi/portspoof.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=93debace98e1a59392f1d89b69eac71c9ccfac3591f4b8327a59bc838eed2802

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

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
