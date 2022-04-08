#
# Copyright (C) 2020-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=scream-receiver
PKG_VERSION:=3.9
PKG_REV:=123182da57a71ac318444551e5068f1f8d986a3f
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/duncanthrax/scream.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=6258217ee558b1fcbb7111f8f61c23235f4a314f319c35e7d5016c1581d7e43c

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
