#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=vblade
PKG_VERSION:=v25
PKG_REV:=5f1a0ba8b9815e3f08a3e2635a17f78bbf2a5b10
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/OpenAoE/vblade.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=a95d0229e02691ca8baec1f4f256afdb94ec9175b44b12b6099dd8eb5a88416a

include $(INCLUDE_DIR)/package.mk

define Package/vblade
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Filesystem
	TITLE:=AoE storage target
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/vblade/description
 The vblade is a minimal ATA over Ethernet (AoE) storage target. Its
 focus is simplicity, not performance or richness of features. It
 exports a seekable file available over an ethernet local area network
 (LAN) via the AoE data storage protocol.
endef

define Package/vblade/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/vblade $(1)/opt/bin
endef

$(eval $(call BuildPackage,vblade))
