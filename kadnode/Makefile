#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=kadnode
PKG_VERSION:=1.0.0-20170507
PKG_REV:=65bc2fd5d8816bb64d26fd9b381ce44500c59bf9
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/mwarning/KadNode.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/kadnode
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=IP Addresses and Names
	DEPENDS:=+libsodium
	TITLE:=P2P DNS and more
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/kadnode/description
 KadNode is a small P2P DNS resolution daemon based on a DHT.
endef

MAKE_FLAGS += \
	FEATURES="auth cmd lpd dns web" \
	LFLAGS="$(TARGET_LDFLAGS) -lsodium"

define Package/kadnode/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/build/kadnode{,-ctl} $(1)/opt/bin/
endef

$(eval $(call BuildPackage,kadnode))
