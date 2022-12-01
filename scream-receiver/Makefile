#
# Copyright (C) 2020-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=scream-receiver
PKG_VERSION:=4.0
PKG_REV:=aa11ca9127c52dbd84879547ce6609b4ba02522a
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/duncanthrax/scream.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=2b9091becfd125c7733d58217d3d18d5207e5c147396f20939022586e7d6b192

CMAKE_SOURCE_SUBDIR:=Receivers/unix

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/scream-receiver
	SECTION:=sound
	CATEGORY:=Sound
	DEPENDS:=+pulseaudio-daemon +libpcap
	TITLE:=Scream audio receiver
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/scream-receiver/description
 scream is a Scream audio receiver using Pulseaudio,
 ALSA or stdout as audio output.
endef

TARGET_LDFLAGS += \
	-Wl,-rpath-link=$(STAGING_DIR)/opt/lib/pulseaudio

define Package/scream-receiver/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/scream $(1)/opt/bin/scream-receiver
endef

$(eval $(call BuildPackage,scream-receiver))
