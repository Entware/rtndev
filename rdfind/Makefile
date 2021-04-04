#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=rdfind
PKG_VERSION:=1.4.1
PKG_REV:=00ebedd232446b2b2204eabdb191d2ad19301eb9
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/pauldreik/rdfind.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=029b53a29daf8c2054a821444ec2e69feff2b5fcb3ed308b650b5e64977c1a5f

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/rdfind
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libnettle +libstdcpp
	TITLE:=find duplicate files utility
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/rdfind/description
 Rdfind is a command line tool that finds duplicate files. It is useful for
 compressing backup directories or just finding duplicate files. It compares
 files based on their content, NOT on their file names.
endef

define Package/rdfind/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/rdfind $(1)/opt/bin
endef

$(eval $(call BuildPackage,rdfind))
