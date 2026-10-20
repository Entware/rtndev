# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=nethogs
PKG_VERSION:=0.9.0
PKG_REV:=2d5e96c5af8edc9dbdfa61ca71464f636a2af291
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/raboof/nethogs.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=823e893cd52471790eadf9788813e469da866ff843bc44382540239de9f8ad7a

include $(INCLUDE_DIR)/package.mk

define Package/nethogs
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libncurses +libpcap +libstdcpp
	TITLE:=NetHogs is a small 'net top' tool
	URL:=https://github.com/raboof/nethogs
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/nethogs/description
 NetHogs is a small 'net top' tool. Instead of breaking the traffic down per
 protocol or per subnet, like most tools do, it groups bandwidth by process.
 If there's suddenly a lot of network traffic, you can fire up NetHogs and
 immediately see which PID is causing this. This makes it easy  to indentify
 programs that have gone wild and are suddenly taking up your bandwidth.
endef

TARGET_CFLAGS += $(TARGET_CPPFLAGS) $(TARGET_LDFLAGS) -fPIC

define Package/nethogs/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/nethogs $(1)/opt/sbin
endef

$(eval $(call BuildPackage,nethogs))
