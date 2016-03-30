#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=vblade
PKG_VERSION:=v23
PKG_REV:=2abc0ca49a5f42b3d6a383e3e205d86ad6a712bd
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/OpenAoE/vblade.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/vblade
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Filesystem
#	DEPENDS=+libneon
	TITLE:=AoE storage target
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, http://entware.net
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
