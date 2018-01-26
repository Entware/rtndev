#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=pwnat
PKG_VERSION:=0.3-20161018
PKG_REV:=10d6e10297abed8e6fb9c7671bc3d96fd5eb63eb
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/samyk/pwnat.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/pwnat
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Firewall
#	DEPENDS:=+libmbedtls
	TITLE:=NAT traversal tool
	URL:=https://samy.pl/pwnat/
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/pwnat/description
 The only tool to punch holes through firewalls/NATs where both
 clients and server can be behind separate NATs without any 3rd party
 involvement.
endef

define Package/pwnat/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/pwnat $(1)/opt/sbin
endef

$(eval $(call BuildPackage,pwnat))
