#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=nload
PKG_VERSION:=0.7.4-20180309
PKG_REV:=8f92dc04fad283abdd2a4538cd4c2093d957d9da
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/rolandriegel/nload.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=fc7eaa62acfd2c48928e5ab0ccabbef6e70a30a3a55191a3fc0dbc755e96d397

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/nload
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libstdcpp +libncurses
	TITLE:=real time monitor for network traffic
	URL:=http://nload.sourceforge.net
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/nload/description
 nload is a real time monitor for network traffic.
endef

define Package/nload/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/$(PKG_NAME) $(1)/opt/bin
endef

$(eval $(call BuildPackage,nload))
