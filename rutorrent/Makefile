# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2025 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=rutorrent
PKG_VERSION:=5.2.5
PKG_RELEASE:=1
PKG_REV:=21697db4b08ec77b67af4075a24f456464481212

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/Novik/ruTorrent.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=7076db684e75987fd9f03c262ec7d9fcf915e6dce894e830c6205d492eac1119

include $(INCLUDE_DIR)/package.mk

RUTORRENT_PLUGINS := \
autotools \
bulk_magnet \
check_port \
chunks \
_cloudflare \
cookies \
cpuload \
create \
data \
datadir \
diskspace \
dump \
edit \
erasedata \
extratio \
extsearch \
feeds \
filedrop \
geoip \
_getdir \
history \
httprpc \
ipad \
loginmgr \
lookat \
mediainfo \
_noty \
_noty2 \
ratio \
retrackers \
rss \
rssurlrewrite \
rutracker_check \
scheduler \
screenshots \
seedingtime \
show_peers_like_wtorrent \
source \
spectrogram \
_task \
theme \
throttle \
tracklabels \
trafic \
unpack \
uploadeta \
xmpp \

RUTORRENT_PLUGIN_DEPENDS_datadir = +php8-cgi
RUTORRENT_PLUGIN_DEPENDS__getdir = +php8-cgi
RUTORRENT_PLUGIN_DEPENDS_edit = +php8-cgi
RUTORRENT_PLUGIN_DEPENDS_extratio = +php8-cgi
RUTORRENT_PLUGIN_DEPENDS_mediainfo = +mediainfo
RUTORRENT_PLUGIN_DEPENDS_rss = +php8-cgi
RUTORRENT_PLUGIN_DEPENDS_screenshots = +ffmpeg
#RUTORRENT_PLUGIN_DEPENDS_spectrogram = +sox
RUTORRENT_PLUGIN_DEPENDS__task = +procps-ng-pgrep
RUTORRENT_PLUGIN_DEPENDS_unpack = +unrar +unzip

define Package/rutorrent/Default
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=BitTorrent
	DEPENDS:=+rtorrent-rpc +coreutils-stat +coreutils-id +gzip +curl
	TITLE:=Yet another web front-end for rTorrent
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/rutorrent
	$(call Package/rutorrent/Default)
	TITLE:=Yet another web front-end for rTorrent
	MENU:=1
endef

define Package/rutorrent/description
 ruTorrent is a front-end for the popular Bittorrent client rTorrent.
endef

define GenPlugin
 define Package/$(1)
	$(call Package/rutorrent/Default)
	DEPENDS:=rutorrent $(RUTORRENT_PLUGIN_DEPENDS_$(2))
	TITLE:=ruTorrent $(2) plugin
 endef

 define Package/$(1)/description
  This is a $(2) Rutorrent plugin.
 endef
endef

$(foreach a,$(RUTORRENT_PLUGINS),$(eval $(call GenPlugin,rutorrent-plugin-$(a),$(a))))

define Build/Configure
endef

define Build/Compile
endef

define Package/rutorrent/install
	$(INSTALL_DIR) $(1)/opt/share/www/rutorrent/plugins
	$(CP) $(PKG_BUILD_DIR)/{conf,css,images,js,lang,php,share,htaccess-example,index.html} \
		$(1)/opt/share/www/rutorrent
	# Entware specific: fix exec path in scripts
	### ! for plugin
	$(SED) 's,^#!.*bash,#!/opt/bin/bash,' $(PKG_BUILD_DIR)/plugins/geoip/make_css.sh
endef

define BuildPlugin
  define Package/$(1)/install
	$(INSTALL_DIR) $$(1)/opt/share/www/rutorrent/plugins/$(2)
	$(CP) $(PKG_BUILD_DIR)/plugins/$(2)/* $$(1)/opt/share/www/rutorrent/plugins/$(2)
  endef

  $$(eval $$(call BuildPackage,$(1)))
endef

$(eval $(call BuildPackage,rutorrent))
$(foreach a,$(RUTORRENT_PLUGINS),$(eval $(call BuildPlugin,rutorrent-plugin-$(a),$(a))))
