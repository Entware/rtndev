#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=radare2
PKG_VERSION:=5.7.4
PKG_REV:=5bc3bf4e6c327121c8f82f20a603382cbba07dbb
PKG_RELEASE:=1


PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/radareorg/radare2.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=147c3b8a8b7a0f7126c9477b0a2994848111ef09d1e4594c36a99ecd80d5c7a8

PKG_BUILD_DEPENDS:=python3/host

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/meson.mk

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
