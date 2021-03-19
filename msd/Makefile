#
# Copyright (C) 2017-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=msd
PKG_VERSION:=3.01.0
PKG_REV:=e82bea960fc9f3a52c698721dc01c8fede468bd5
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/rozhuk-im/msd.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/msd
	SECTION:=multimedia
	CATEGORY:=Multimedia
	TITLE:=Multi Stream daemon
	URL:=http://www.netlab.linkpc.net/wiki/en:software:msd:index
endef

define Package/msd/description
 Multi stream daemon. Program for organizing IP TV
 streaming on the network via HTTP.
endef

define Package/msd/conffiles
/opt/etc/msd_channels2.conf
/opt/etc/msd_channels.conf
/opt/etc/msd.conf
/opt/etc/msd_minimal.conf
endef

define Package/msd/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/msd $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/msd
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/conf/*.conf $(1)/opt/etc
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S29msd $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,msd))
