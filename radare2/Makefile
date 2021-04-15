#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=radare2
PKG_VERSION:=5.2.0
PKG_REV:=cf3db945083fb4dab951874e5ec1283128deab11
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/radareorg/radare2.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=c91fa6da0d1204dccb263211612365e0221c406c680f36f7ebf15c652f9f296d

include $(INCLUDE_DIR)/package.mk
include ../../packages/devel/meson/meson.mk

define Package/radare2
	SECTION:=devel
	CATEGORY:=Development
	DEPENDS:=@!TARGET_armv7_2_6 +libuv
	TITLE:=reverse engineering framework
	URL:=https://www.radare.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/radare2/description
 UNIX-like reverse engineering framework and command-line toolset.
endef

define Package/radare2/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/bin $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libr_* $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/share/radare2
	$(CP) $(PKG_INSTALL_DIR)/opt/share/radare2/$(PKG_VERSION) \
		$(1)/opt/share/radare2
endef

$(eval $(call BuildPackage,radare2))
